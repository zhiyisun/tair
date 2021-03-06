SUBDIRS=. tools

AM_CPPFLAGS=-DWITH_TBUTIL -fPIC -I$(TBLIB_ROOT)/include/tbsys -I$(TBLIB_ROOT)/include/tbnet -I${top_builddir}/src/storage/ldb/leveldb/include -I${top_builddir}/src/storage/ldb/leveldb/ -I${top_srcdir}/src -I${top_srcdir}/src/storage -I${top_srcdir}/src/common -I.

if WITH_TCMALLOC
AM_CPPFLAGS += -DWITH_TCMALLOC
endif

AM_LDFLAGS=-pthread -lrt ${GCOV_LIB}
noinst_LIBRARIES=libldb.a

libldb_a_SOURCES=ldb_manager.cpp ldb_manager.hpp ldb_instance.hpp ldb_instance.cpp stat_manager.cpp stat_manager.hpp ldb_define.hpp ldb_define.cpp bg_task.hpp bg_task.cpp ldb_comparator.hpp ldb_numeric_comparator.cpp ldb_comparator.cpp ldb_gc_factory.hpp ldb_gc_factory.cpp ldb_cache_stat.hpp ldb_cache_stat.cpp ldb_bloom.cpp ldb_remote_sync_logger.hpp ldb_remote_sync_logger.cpp ldb_balancer.hpp ldb_balancer.cpp


##############################
# leveldb && snappy
##############################
PORTCFLAGS= -fno-builtin-memcmp \
	    -pthread -DOS_LINUX \
	    -DSNAPPY -I$./snappy \
	    ${LEVELDB_PORT_CFLAGS}

noinst_LIBRARIES += libleveldb.a libsnappy.a

leveldb_srcdir = ./leveldb
snappy_srcdir = ./snappy

libleveldb_a_CPPFLAGS=${AM_CPPFLAGS} ${PORTCFLAGS}
libleveldb_a_SOURCES= \
	leveldb/db/builder.cc leveldb/db/c.cc leveldb/db/db_impl.cc \
	leveldb/db/db_iter.cc \
	leveldb/db/filename.cc leveldb/db/dbformat.cc leveldb/db/log_reader.cc \
	leveldb/db/log_writer.cc leveldb/db/memtable.cc leveldb/db/repair.cc \
	leveldb/db/table_cache.cc leveldb/db/version_edit.cc leveldb/db/version_set.cc \
	leveldb/db/write_batch.cc leveldb/port/port_posix.cc \
	leveldb/table/block.cc leveldb/table/block_builder.cc leveldb/table/format.cc \
	leveldb/table/iterator.cc leveldb/table/merger.cc leveldb/table/table.cc \
	leveldb/table/table_builder.cc leveldb/table/two_level_iterator.cc \
	leveldb/table/filter_block.cc leveldb/table/filter_block.h \
	leveldb/util/arena.cc leveldb/util/cache.cc leveldb/util/coding.cc \
	leveldb/util/comparator.cc leveldb/util/crc32c.cc \
	leveldb/util/env.cc leveldb/util/env_posix.cc leveldb/util/hash.cc \
	leveldb/util/histogram.cc leveldb/util/logging.cc \
	leveldb/util/options.cc leveldb/util/status.cc leveldb/util/config.h \
	leveldb/util/config.cc leveldb/util/filter_policy.cc leveldb/util/bloom.cc \
	leveldb/db/builder.h leveldb/db/db_iter.h leveldb/db/filename.h \
	leveldb/db/log_reader.h leveldb/db/memtable.h leveldb/db/snapshot.h \
	leveldb/db/version_edit.h leveldb/db/version_set.h \
	leveldb/db/write_batch_internal.h leveldb/db/db_impl.h leveldb/db/dbformat.h \
	leveldb/db/log_format.h leveldb/db/log_writer.h leveldb/db/skiplist.h \
	leveldb/db/table_cache.h leveldb/port/atomic_pointer.h \
	leveldb/port/port.h leveldb/port/port_android.h leveldb/port/port_example.h \
	leveldb/port/port_posix.h leveldb/port/sha1_portable.h leveldb/table/block.h \
	leveldb/table/block_builder.h leveldb/table/format.h leveldb/table/iterator_wrapper.h \
	leveldb/table/merger.h leveldb/table/two_level_iterator.h leveldb/util/arena.h \
	leveldb/util/coding.h leveldb/util/config.h \
	leveldb/util/crc32c.h leveldb/util/hash.h leveldb/util/histogram.h \
	leveldb/util/logging.h leveldb/util/mutexlock.h leveldb/util/posix_logger.h \
	leveldb/util/random.h leveldb/include/leveldb/c.h \
	leveldb/include/leveldb/cache.h leveldb/include/leveldb/db.h \
	leveldb/include/leveldb/env.h leveldb/include/leveldb/iterator.h \
	leveldb/include/leveldb/options.h leveldb/include/leveldb/slice.h \
	leveldb/include/leveldb/table.h leveldb/include/leveldb/table_builder.h \
	leveldb/include/leveldb/write_batch.h leveldb/include/leveldb/status.h \
	leveldb/include/leveldb/comparator.h leveldb/include/leveldb/filter_policy.h

libsnappy_a_SOURCES= \
	snappy/snappy-internal.h snappy/snappy-c.h snappy/snappy-c.cc \
	snappy/snappy-sinksource.cc snappy/snappy-sinksource.h \
	snappy/snappy-stubs-internal.h snappy/snappy-stubs-internal.cc\
	snappy/snappy-stubs-public.h.in snappy/snappy.cc snappy/snappy.h\
	snappy/config.h.in

##############################
