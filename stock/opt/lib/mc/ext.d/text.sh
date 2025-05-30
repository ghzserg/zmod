#!/bin/sh

# $1 - action
# $2 - type of archive
# $3 - pager

action=$1
filetype=$2
pager=$3

[ -n "${MC_XDG_OPEN}" ] || MC_XDG_OPEN="xdg-open"

get_unpacker() {
    filetype=$1
    case "${filetype}" in
    man.gz)
        unpacker="gzip -dc"
        ;;
    man.bz)
        unpacker="bzip -dc"
        ;;
    man.bz2)
        unpacker="bzip2 -dc"
        ;;
    man.lz)
        unpacker="lzip -dc"
        ;;
    man.lz4)
        unpacker="lz4 -dc"
        ;;
    man.lzma)
        unpacker="lzma -dc"
        ;;
    man.lzo)
        unpacker="lzop -dc"
        ;;
    man.xz)
        unpacker="xz -dc"
        ;;
    man.zst)
        unpacker="zstd -dc"
        ;;
    esac
    echo ${unpacker}
}


do_view_action() {
    filetype=$1

    unpacker=`get_unpacker ${filetype}`

    case "${filetype}" in
    man)
        case "${MC_EXT_FILENAME}" in
        */log/*|*/logs/*)
            cat "${MC_EXT_FILENAME}"
            ;;
        *)
            MANROFFOPT=-c MAN_KEEP_FORMATTING=1 man -P cat "${MC_EXT_FILENAME}"
            ;;
        esac
        ;;
    pod)
        pod2man "${MC_EXT_FILENAME}" | nroff -c -Tlatin1 -mandoc
        ;;
    nroff.me)
        nroff -c -Tlatin1 -me "${MC_EXT_FILENAME}"
        ;;
    nroff.ms)
        nroff -c -Tlatin1 -ms "${MC_EXT_FILENAME}"
        ;;
    man.gz|man.bz|man.bz2|man.lz|man.lz4|man.lzma|man.lzo|man.xz|man.zst)
        case "${MC_EXT_FILENAME}" in
        */log/*|*/logs/*)
            ${unpacker} "${MC_EXT_FILENAME}"
            ;;
        *)
            # "man" takes care of uncompressing.
            # This way the stdin is left intact so the correct width is used.
            MANROFFOPT=-c MAN_KEEP_FORMATTING=1 man -P cat "${MC_EXT_FILENAME}"
            ;;
        esac
        ;;
    *)
        ;;
    esac
}

do_open_action() {
    filetype=$1
    pager=$2

    unpacker=`get_unpacker ${filetype}`

    case "${filetype}" in
    info)
        info -f "${MC_EXT_FILENAME}"
        ;;
    man)
        case "${MC_EXT_FILENAME}" in
        */log/*|*/logs/*)
            cat "${MC_EXT_FILENAME}"
            ;;
        *)
            { zsoelim "${MC_EXT_FILENAME}" 2>/dev/null || cat "${MC_EXT_FILENAME}"; } | \
                nroff -c -Tlatin1 -mandoc
            ;;
        esac | ${pager}
        ;;
    pod)
        pod2man "${MC_EXT_FILENAME}" | nroff -c -Tlatin1 -mandoc | ${pager}
        ;;
    nroff.me)
        nroff -c -Tlatin1 -me "${MC_EXT_FILENAME}" | ${pager}
        ;;
    nroff.ms)
        nroff -c -Tlatin1 -ms "${MC_EXT_FILENAME}" | ${pager}
        ;;
    man.gz|man.bz|man.bz2|man.lz|man.lz4|man.lzma|man.lzo|man.xz|man.zst)
        case "${MC_EXT_FILENAME}" in
        */log/*|*/logs/*)
            ${unpacker} "${MC_EXT_FILENAME}"
            ;;
        *)
            ${unpacker} "${MC_EXT_FILENAME}" | nroff -c -Tlatin1 -mandoc
            ;;
        esac | ${pager}
        ;;
    chm)
        if [ -n "$DISPLAY" ]; then
            which kchmviewer > /dev/null 2>&1 \
                && (kchmviewer "${MC_EXT_FILENAME}" &) \
                || (xchm "${MC_EXT_FILENAME}" &)
        else
            chm_http "${MC_EXT_FILENAME}" & elinks http://localhost:8080/index.html
            kill -INT %1
        fi
        ;;
    *)
        ;;
    esac
}

case "${action}" in
view)
    do_view_action "${filetype}"
    ;;
open)
    ("${MC_XDG_OPEN}" "${MC_EXT_FILENAME}" >/dev/null 2>&1) || \
        do_open_action "${filetype}" "${pager}"
    ;;
*)
    ;;
esac
