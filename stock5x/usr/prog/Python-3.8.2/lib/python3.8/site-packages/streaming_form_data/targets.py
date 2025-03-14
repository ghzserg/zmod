import hashlib
from typing import Callable, Optional


class BaseTarget:
    """
    Targets determine what to do with some input once the parser is done
    processing it. Any new Target should inherit from this base class and
    override the :code:`data_received` function.

    Attributes:
        multipart_filename: the name of the file advertised by the user,
            extracted from the :code:`Content-Disposition` header. Please note
            that this value comes directly from the user input and is not
            sanitized, so be careful in using it directly.
        multipart_content_type: MIME Content-Type of the file, extracted from
            the :code:`Content-Type` HTTP header
    """

    def __init__(self, validator: Optional[Callable] = None):
        self.multipart_filename = None
        self.multipart_content_type = None

        self._started = False
        self._finished = False
        self._validator = validator

    def _validate(self, chunk: bytes):
        if self._validator:
            self._validator(chunk)

    def start(self):
        self._started = True
        self.on_start()

    def on_start(self):
        pass

    def data_received(self, chunk: bytes):
        self._validate(chunk)
        self.on_data_received(chunk)

    def on_data_received(self, chunk: bytes):
        raise NotImplementedError()

    def finish(self):
        self.on_finish()
        self._finished = True

    def on_finish(self):
        pass


class NullTarget(BaseTarget):
    """NullTarget ignores whatever input is passed in.

    This is mostly useful for internal use and should (normally) not be
    required by external users.
    """

    def on_data_received(self, chunk: bytes):
        pass


class ValueTarget(BaseTarget):
    """ValueTarget stores the input in an in-memory list of bytes.

    This is useful in case you'd like to have the value contained in an
    in-memory string.
    """

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        self._values = []

    def on_data_received(self, chunk: bytes):
        self._values.append(chunk)

    @property
    def value(self):
        return b''.join(self._values)


class FileTarget(BaseTarget):
    """FileTarget writes (streams) the input to an on-disk file."""

    def __init__(
        self, filename: str, allow_overwrite: bool = True, *args, **kwargs
    ):
        super().__init__(*args, **kwargs)

        self.filename = filename

        self._mode = 'wb' if allow_overwrite else 'xb'
        self._fd = None

    def on_start(self):
        self._fd = open(self.filename, self._mode)

    def on_data_received(self, chunk: bytes):
        if self._fd:
            self._fd.write(chunk)

    def on_finish(self):
        if self._fd:
            self._fd.close()


class SHA256Target(BaseTarget):
    """SHA256Target calculates the SHA256 hash of the given input."""

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        self._hash = hashlib.sha256()

    def on_data_received(self, chunk: bytes):
        self._hash.update(chunk)

    @property
    def value(self):
        return self._hash.hexdigest()
