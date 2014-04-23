#include <cos_component.h>
#include <torrent.h>
#include <torlib.h>

#include <cbuf.h>
#include <print.h>
#include <cos_synchronization.h>
#include <evt.h>
#include <cos_alloc.h>
#include <cos_map.h>
#include <fs.h>

#include "../../../lib/libsqlite/sqlite3.h"

#define DEBUG
#ifdef  DEBUG
  #define LOGD(fmt, ...) printc("[SQLite Torrent] "fmt"\n", ##__VA_ARGS__)
#else
  #define LOGD(fmt, ...)
#endif /* DEBUG */ 

static sqlite3 *g_handler[16];

td_t tsplit(spdid_t spdid, td_t td, char *param, int len, tor_flags_t tflags, long evtid) 
{
    sqlite3 *db;
    
    if (SQLITE_OK != sqlite3_open_v2(":memory:", &db, SQLITE_OPEN_READWRITE, NULL)) {
        LOGD("ERR: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    LOGD("Datebase connected.\n");

    td_t rtd = 0;
    g_handler[rtd] = db;
    return rtd;
}

int tmerge(spdid_t spdid, td_t td, td_t td_into, char *param, int len)
{
	int ret = 0;
	return ret;
}

void trelease(spdid_t spdid, td_t td)
{
    sqlite3 *db = g_handler[td];
    sqlite3_close(db);
    LOGD("Database closed.\n");
}

int tread(spdid_t spdid, td_t td, int cbid, int sz)
{
	int ret = -1;
	return ret;
}

int twrite(spdid_t spdid, td_t td, int cbid, int sz)
{
	int ret = -1;
	return ret;
}

int cos_init(void)
{
    LOGD("Component Init.");
	return 0;
}
