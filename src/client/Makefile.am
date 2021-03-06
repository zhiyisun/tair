AM_CPPFLAGS= -fPIC -I${top_srcdir}/src \
	    -I$(TBLIB_ROOT)/include/tbsys \
	    -I$(TBLIB_ROOT)/include/tbnet \
	    -I${top_srcdir}/src/storage/fdb \
	    -I${top_srcdir}/src/storage/mdb \
            -I${top_srcdir}/src/common \
	    -I${top_srcdir}/src/storage/ \
            -I${top_srcdir}/src/packets \
            -I${top_srcdir}/src/dataserver \
            -I${top_srcdir}/src/statserver/include \
	    -I${top_srcdir}/src/plugin

LDADD=$(TBLIB_ROOT)/lib/libtbnet.a \
      $(TBLIB_ROOT)/lib/libtbsys.a -lrt

multi_cluster_impl_source=tair_multi_cluster_client_impl.hpp tair_multi_cluster_client_impl.cpp \
			  cluster_handler_manager.hpp cluster_handler_manager.cpp \
			  cluster_info_updater.hpp cluster_info_updater.cpp

#daimond
if WITH_DIAMOND
mc_impl_source=diamond_manager.hpp diamond_manager.cpp  cluster_controller.hpp cluster_controller.cpp \
					tair_mc_client_api.hpp  tair_mc_client_api.cpp
mc_impl_lib=libtairmcclientapi.la
mc_impl_header=tair_mc_client_api.hpp diamond_manager.hpp cluster_controller.hpp 
endif

api_source_list=tair_client_api.cpp i_tair_client_impl.hpp i_tair_client_impl.cpp tair_client_api_impl.cpp \
		../packets/packet_factory.cpp \
		../packets/packet_streamer.cpp \
		../common/data_entry.cpp \
		tair_client_capi.hpp tair_client_api.hpp \
	       	tair_client_api_impl.hpp tair_client_capi.hpp \
          local_cache.hpp local_cache.hpp \
          string_local_cache.h string_local_cache.cpp \
          data_entry_local_cache.h data_entry_local_cache.cpp \
		tair_client.hpp ${multi_cluster_impl_source}

if WITH_READLINE
READLINE_LDFLAGS= -lreadline -ltermcap
endif

if WITH_COMPRESS
COMPRESS_LDFLAGS=-lsnappy
endif

AM_LDFLAGS=-pthread -lz -lrt ${GCOV_LIB} ${COMPRESS_LDFLAGS}

lib_LTLIBRARIES=libtairclientapi.la libtairclientapi_c.la libtairclientapi_impl.la ${mc_impl_lib}
sbin_PROGRAMS=tairclient keycleantool

tairclient_SOURCES=tair_client.cpp
tairclient_LDADD=libtairclientapi.la ${READLINE_LDFLAGS} ${LDADD}
tairclient_LDFLAGS= -static

keycleantool_SOURCES=tair_key_clean.cpp del_job.hpp nonblock_queue.hpp clean_worker.hpp config_loader.hpp
keycleantool_LDADD=libtairclientapi.la ${LDADD}
keycleantool_LDFLAGS= -static

libtairclientapi_la_SOURCES=${api_source_list}
libtairclientapi_impl_la_SOURCES=${api_source_list}
libtairclientapi_c_la_SOURCES=${api_source_list} tair_client_capi.cpp
libtairclientapi_c_la_LIBADD=libtairclientapi.la
if WITH_DIAMOND
libtairmcclientapi_la_SOURCES=${mc_impl_source}
libtairmcclientapi_la_LIBADD=libtairclientapi.la -ljsoncpp
endif

include_HEADERS=tair_client_api.hpp tair_client_capi.hpp local_cache.h local_cache.hpp data_entry_local_cache.h ${mc_impl_header}
