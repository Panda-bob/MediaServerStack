set(exosip2_SOURCES
	eXcall_api.c
    eXconf.c
    eXinsubscription_api.c
    eXmessage_api.c
    eXoptions_api.c
    eXosip.c
    eXpublish_api.c
    eXregister_api.c
    eXsubscription_api.c
    eXtl_dtls.c
    eXtl_tcp.c
    eXtl_tls.c
    eXtl_udp.c
    eXtransport.c
    eXutils.c
    inet_ntop.c
    jauth.c
    jcall.c
    jcallback.c
    jdialog.c
    jevents.c
    jnotify.c
    jpipe.c
    jpublish.c
    jreg.c
    jrequest.c
    jresponse.c
    jsubscribe.c
    milenage.c
    misc.c
    rijndael.c
    sdp_offans.c
    udp.c
	)

if(${CMAKE_SYSTEM_NAME} MATCHES Windows)
	ADD_DEFINITIONS(/D"OSIP2_EXPORTS" /D"OSIP_MT")
else()
	ADD_DEFINITIONS("-DOSIP2_EXPORTS -DOSIP_MT -DHAVE_RESOLV_H -DHAVE_PTHREAD -DHAVE_SEMAPHORE_H -DHAVE_STRUCT_TIMEVAL")
	set(CMAKE_C_FLAGS "-Wall -Wcast-align -Wchar-subscripts -Wformat -Winline -Wmissing-declarations -Wmissing-prototypes -Wnested-externs -Wpointer-arith -DENABLE_TRACE -g -O2 -MD -MP -MF -fPIC -DPIC")
	#set(CMAKE_C_FLAGS "-Wnested-externs")	
endif()


if(${CMAKE_SYSTEM_NAME} MATCHES Windows)
    #ADD_DEFINITIONS(/D"ASN1_HAS_IOSTREAM" /D"ASN1_STATIC")
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES Linux)
    ADD_DEFINITIONS( -DHAVE_ARES_H)
    ADD_DEFINITIONS( -DHAVE_ARPA_INET_H)
    ADD_DEFINITIONS( -DHAVE_ARPA_NAMESER_COMPAT_H)
    ADD_DEFINITIONS( -DHAVE_ARPA_NAMESER_H)
    ADD_DEFINITIONS( -DHAVE_ASSERT_H)
    # /* Define to 1 if you have the <ctype.h> header file. */
    ADD_DEFINITIONS( -DHAVE_CTYPE_H)

    #/* Define to 1 if you have the <dlfcn.h> header file. */
    ADD_DEFINITIONS( -DHAVE_DLFCN_H)

    #/* Define to 1 if you have the <fcntl.h> header file. */
    ADD_DEFINITIONS( -DHAVE_FCNTL_H)

    #/* Define to 1 if you have the `getifaddrs' function. */
    ADD_DEFINITIONS( -DHAVE_GETIFADDRS)

    #/* Define to 1 if you have the `gmtime' function. */
    ADD_DEFINITIONS( -DHAVE_GMTIME)

    #/* Define to 1 if you have the `gmtime_r' function. */
    ADD_DEFINITIONS( -DHAVE_GMTIME_R)

    #/* Define to 1 if you have the <inttypes.h> header file. */
    ADD_DEFINITIONS( -DHAVE_INTTYPES_H)

    #/* Define to 1 if you have the <limits.h> header file. */
    ADD_DEFINITIONS( -DHAVE_LIMITS_H)

    #/* Define to 1 if you have the <malloc.h> header file. */
    ADD_DEFINITIONS( -DHAVE_MALLOC_H)

    #/* Define to 1 if you have the <memory.h> header file. */
    ADD_DEFINITIONS( -DHAVE_MEMORY_H)

    #/* Define to 1 if you have the <netdb.h> header file. */
    ADD_DEFINITIONS( -DHAVE_NETDB_H)

    #/* Define to 1 if you have the <netinet/in.h> header file. */
    ADD_DEFINITIONS( -DHAVE_NETINET_IN_H)

    #/* Define to 1 if you have the <netinet/tcp.h> header file. */
    ADD_DEFINITIONS( -DHAVE_NETINET_TCP_H)

    #/* Define to 1 if you have the <openssl/ssl.h> header file. */
    ADD_DEFINITIONS( -DHAVE_OPENSSL_SSL_H)

    #/* Define if you have POSIX threads libraries and header files. */
    ADD_DEFINITIONS( -DHAVE_PTHREAD)

    #/* Define to 1 if you have the <regex.h> header file. */
    ADD_DEFINITIONS( -DHAVE_REGEX_H)

    #/* Define to 1 if you have the <resolv.h> header file. */
    ADD_DEFINITIONS( -DHAVE_RESOLV_H)

    #/* Define to 1 if you have the <semaphore.h> header file. */
    ADD_DEFINITIONS( -DHAVE_SEMAPHORE_H)

    # /* Define to 1 if you have the <signal.h> header file. */
    ADD_DEFINITIONS( -DHAVE_SIGNAL_H)

    #/* Define to 1 if you have the <stdarg.h> header file. */
    ADD_DEFINITIONS( -DHAVE_STDARG_H)

    #/* Define to 1 if you have the <stdint.h> header file. */
    ADD_DEFINITIONS( -DHAVE_STDINT_H)

    #/* Define to 1 if you have the <stdio.h> header file. */
    ADD_DEFINITIONS( -DHAVE_STDIO_H)

    #/* Define to 1 if you have the <stdlib.h> header file. */
    ADD_DEFINITIONS( -DHAVE_STDLIB_H)

    #/* Define to 1 if you have the <string.h> header file. */
    ADD_DEFINITIONS( -DHAVE_STRING_H)

    #/* Define to 1 if you have the <sys/epoll.h> header file. */
    ADD_DEFINITIONS( -DHAVE_SYS_EPOLL_H)

    #/* Define to 1 if you have the <sys/ioctl.h> header file. */
    ADD_DEFINITIONS( -DHAVE_SYS_IOCTL_H)

    #/* Define to 1 if you have the <sys/param.h> header file. */
    ADD_DEFINITIONS( -DHAVE_SYS_PARAM_H)

    #/* Define to 1 if you have the <sys/select.h> header file. */
    ADD_DEFINITIONS( -DHAVE_SYS_SELECT_H)

    #/* Define to 1 if you have the <sys/sem.h> header file. */
    ADD_DEFINITIONS( -DHAVE_SYS_SEM_H)

    #/* Define to 1 if you have the <sys/signal.h> header file. */
    ADD_DEFINITIONS( -DHAVE_SYS_SIGNAL_H)

    #/* Define to 1 if you have the <sys/socket.h> header file. */
    ADD_DEFINITIONS( -DHAVE_SYS_SOCKET_H)

    #/* Define to 1 if you have the <sys/soundcard.h> header file. */
    ADD_DEFINITIONS( -DHAVE_SYS_SOUNDCARD_H)

    #/* Define to 1 if you have the <sys/stat.h> header file. */
    ADD_DEFINITIONS( -DHAVE_SYS_STAT_H)

    #/* Define to 1 if you have the <sys/time.h> header file. */
    ADD_DEFINITIONS( -DHAVE_SYS_TIME_H)

    #/* Define to 1 if you have the <sys/types.h> header file. */
    ADD_DEFINITIONS( -DHAVE_SYS_TYPES_H)

    #/* Define to 1 if you have the <unistd.h> header file. */
    ADD_DEFINITIONS( -DHAVE_UNISTD_H)

    #/* Define to 1 if you have the <varargs.h> header file. */
    ADD_DEFINITIONS( -DHAVE_VARARGS_H)

endif()

#include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(/usr/local/include)

ADD_LIBRARY(exosip2 STATIC
    ${exosip2_SOURCES}
    )
# Set output directory
set_target_properties(exosip2 
#controlcenter_SHARED
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
