import cgi
from typing import Mapping, Type

from streaming_form_data._parser import ErrorGroup, _Parser  # type: ignore
from streaming_form_data.targets import BaseTarget


class ParseFailedException(Exception):
    pass


def parse_content_boundary(headers: Mapping[str, str]) -> bytes:
    content_type = None

    for key in headers.keys():
        if key.lower() == 'content-type':
            content_type = headers.get(key)
            break

    if not content_type:
        raise ParseFailedException('Missing Content-Type header')

    value, params = cgi.parse_header(content_type)

    if not value or value.lower() != 'multipart/form-data':
        raise ParseFailedException('Content-Type is not multipart/form-data')

    boundary = params.get('boundary')
    if not boundary:
        raise ParseFailedException('Boundary not found')

    return boundary.encode('utf-8')


class StreamingFormDataParser:
    def __init__(self, headers: Mapping[str, str]):
        self.headers = headers

        raw_boundary = parse_content_boundary(headers)

        delimiter = b'\r\n--' + raw_boundary + b'\r\n'
        ender = b'\r\n--' + raw_boundary + b'--'

        self._parser = _Parser(delimiter, ender)

        self._running = False

    def register(self, name: str, target: Type[BaseTarget]):
        if self._running:
            raise ParseFailedException(
                'Registering parts not allowed while parser is running'
            )

        self._parser.register(name, target)

    def data_received(self, data: bytes):
        if not self._running:
            self._running = True

        result = self._parser.data_received(data)

        if result > 0:
            if ErrorGroup.Internal <= result < ErrorGroup.Delimiting:
                message = 'internal errors'
            elif ErrorGroup.Delimiting <= result < ErrorGroup.PartHeaders:
                message = 'delimiting multipart stream into parts'
            elif ErrorGroup.PartHeaders <= result:
                message = 'parsing specific part headers'

            raise ParseFailedException(
                '_parser.data_received failed with {}'.format(message)
            )
