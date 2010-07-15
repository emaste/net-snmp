/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.12 $ of : mfd-data-access.m2c,v $ 
 *
 * $Id$
 */
/*
 * standard Net-SNMP includes 
 */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/*
 * include our parent header 
 */
#include "ipAddressTable.h"


#include "ipAddressTable_data_access.h"

/** @defgroup data_access data_access: Routines to access data
 *
 * These routines are used to locate the data used to satisfy
 * requests.
 * 
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ipAddressTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * ipAddressTable is subid 34 of ip.
 * Its status is Current.
 * OID: .1.3.6.1.2.1.4.34, length: 8
 */

/**
 * initialization for ipAddressTable data access
 *
 * This function is called during startup to allow you to
 * allocate any resources you need for the data table.
 *
 * @param ipAddressTable_reg
 *        Pointer to ipAddressTable_registration
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : unrecoverable error.
 */
int
ipAddressTable_init_data(ipAddressTable_registration_ptr
                         ipAddressTable_reg)
{
    DEBUGMSGTL(("verbose:ipAddressTable:ipAddressTable_init_data",
                "called\n"));

    /*
     * TODO:303:o: Initialize ipAddressTable data.
     */

    return MFD_SUCCESS;
}                               /* ipAddressTable_init_data */

/**
 * container-cached overview
 *
 */

/***********************************************************************
 *
 * cache
 *
 ***********************************************************************/
/**
 * container initialization
 *
 * @param container_ptr_ptr A pointer to a container pointer. If you
 *        create a custom container, use this parameter to return it
 *        to the MFD helper. If set to NULL, the MFD helper will
 *        allocate a container for you.
 * @param  cache A pointer to a cache structure. You can set the timeout
 *         and other cache flags using this pointer.
 *
 *  This function is called at startup to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases. If no custom
 *  container is allocated, the MFD code will create one for your.
 *
 *  This is also the place to set up cache behavior. The default, to
 *  simply set the cache timeout, will work well with the default
 *  container. If you are using a custom container, you may want to
 *  look at the cache helper documentation to see if there are any
 *  flags you want to set.
 *
 * @remark
 *  This would also be a good place to do any initialization needed
 *  for you data source. For example, opening a connection to another
 *  process that will supply the data, opening a database, etc.
 */
void
ipAddressTable_container_init(netsnmp_container ** container_ptr_ptr,
                              netsnmp_cache * cache)
{
    DEBUGMSGTL(("verbose:ipAddressTable:ipAddressTable_container_init",
                "called\n"));

    if ((NULL == cache) || (NULL == container_ptr_ptr)) {
        snmp_log(LOG_ERR, "bad params to ipAddressTable_container_init\n");
        return;
    }

    /*
     * For advanced users, you can use a custom container. If you
     * do not create one, one will be created for you.
     */
    *container_ptr_ptr = NULL;

    /*
     * TODO:345:A: Set up ipAddressTable cache properties.
     *
     * Also for advanced users, you can set parameters for the
     * cache. Do not change the magic pointer, as it is used
     * by the MFD helper.
     */
    cache->timeout = IPADDRESSTABLE_CACHE_TIMEOUT;      /* seconds */
}                               /* ipAddressTable_container_init */

/**
 * load cache data
 *
 * TODO:350:M: Implement ipAddressTable cache load
 *
 * @param container container to which items should be inserted
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_RESOURCE_UNAVAILABLE : Can't access data source
 * @retval MFD_ERROR                : other error.
 *
 *  This function is called to cache the index(es) (and data, optionally)
 *  for the every row in the data set.
 *
 * @remark
 *  While loading the cache, the only important thing is the indexes.
 *  If access to your data is cheap/fast (e.g. you have a pointer to a
 *  structure in memory), it would make sense to update the data here.
 *  If, however, the accessing the data invovles more work (e.g. parsing
 *  some other existing data, or peforming calculations to derive the data),
 *  then you can limit yourself to setting the indexes and saving any
 *  information you will need later. Then use the saved information in
 *  ipAddressTable_row_prep() for populating data.
 *
 * @note
 *  If you need consistency between rows (like you want statistics
 *  for each row to be from the same time frame), you should set all
 *  data here.
 *
 */
int
ipAddressTable_cache_load(netsnmp_container * container)
{
    ipAddressTable_rowreq_ctx *rowreq_ctx;
    size_t          count = 0;

    DEBUGMSGTL(("verbose:ipAddressTable:ipAddressTable_cache_load",
                "called\n"));

    /*
     * TODO:351:M: |-> Load/update data in the ipAddressTable container.
     * loop over your ipAddressTable data, allocate a rowreq context,
     * set the index(es) [and data, optionally] and insert into
     * the container.
     */
    while (1) {
        /*
         * check for end of data; bail out if there is no more data
         */
        if (1)
            break;

        /*
         * TODO:352:M: |   |-> set indexes in new ipAddressTable rowreq context.
         * data context will be set from the param (unless NULL,
         *      in which case a new data context will be allocated)
         */
        rowreq_ctx = ipAddressTable_allocate_rowreq_ctx(NULL);
        if (NULL == rowreq_ctx) {
            snmp_log(LOG_ERR, "memory allocation failed\n");
            return MFD_RESOURCE_UNAVAILABLE;
        }
        if (MFD_SUCCESS !=
            ipAddressTable_indexes_set(rowreq_ctx, ipAddressAddrType,
                                       ipAddressAddr, ipAddressAddr_len)) {
            snmp_log(LOG_ERR,
                     "error setting index while loading "
                     "ipAddressTable cache.\n");
            ipAddressTable_release_rowreq_ctx(rowreq_ctx);
            continue;
        }

        /*
         * TODO:352:r: |   |-> populate ipAddressTable data context.
         * Populate data context here. (optionally, delay until row prep)
         */
        /*
         * TRANSIENT or semi-TRANSIENT data:
         * copy data or save any info needed to do it in row_prep.
         */
        /*
         * setup/save data for ipAddressIfIndex
         * ipAddressIfIndex(3)/InterfaceIndex/ASN_INTEGER/long(long)//l/A/W/e/R/d/H
         */
        /*
         * setup/save data for ipAddressType
         * ipAddressType(4)/INTEGER/ASN_INTEGER/long(u_long)//l/A/W/E/r/D/h
         */
        /*
         * setup/save data for ipAddressPrefix
         * ipAddressPrefix(5)/RowPointer/ASN_OBJECT_ID/oid(oid)//L/A/w/e/r/D/h
         */
        /*
         * setup/save data for ipAddressOrigin
         * ipAddressOrigin(6)/IpAddressOriginTC/ASN_INTEGER/long(u_long)//l/A/w/E/r/d/h
         */
        /*
         * setup/save data for ipAddressStatus
         * ipAddressStatus(7)/IpAddressStatusTC/ASN_INTEGER/long(u_long)//l/A/W/E/r/D/h
         */
        /*
         * setup/save data for ipAddressCreated
         * ipAddressCreated(8)/TimeStamp/ASN_TIMETICKS/u_long(u_long)//l/A/w/e/r/d/h
         */
        /*
         * setup/save data for ipAddressLastChanged
         * ipAddressLastChanged(9)/TimeStamp/ASN_TIMETICKS/u_long(u_long)//l/A/w/e/r/d/h
         */
        /*
         * setup/save data for ipAddressRowStatus
         * ipAddressRowStatus(10)/RowStatus/ASN_INTEGER/long(u_long)//l/A/W/E/r/d/h
         */
        /*
         * setup/save data for ipAddressStorageType
         * ipAddressStorageType(11)/StorageType/ASN_INTEGER/long(u_long)//l/A/W/E/r/D/h
         */

        /*
         * insert into table container
         */
        CONTAINER_INSERT(container, rowreq_ctx);
        ++count;
    }

    DEBUGMSGT(("verbose:ipAddressTable:ipAddressTable_cache_load",
               "inserted %d records\n", count));

    return MFD_SUCCESS;
}                               /* ipAddressTable_cache_load */

/**
 * cache clean up
 *
 * @param container container with all current items
 *
 *  This optional callback is called prior to all
 *  item's being removed from the container. If you
 *  need to do any processing before that, do it here.
 *
 * @note
 *  The MFD helper will take care of releasing all the row contexts.
 *
 */
void
ipAddressTable_cache_free(netsnmp_container * container)
{
    DEBUGMSGTL(("verbose:ipAddressTable:ipAddressTable_cache_free",
                "called\n"));

    /*
     * TODO:380:M: Free ipAddressTable cache.
     */
}                               /* ipAddressTable_cache_free */

/**
 * prepare row for processing.
 *
 *  When the agent has located the row for a request, this function is
 *  called to prepare the row for processing. If you fully populated
 *  the data context during the index setup phase, you may not need to
 *  do anything.
 *
 * @param rowreq_ctx pointer to a context.
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 */
int
ipAddressTable_row_prep(ipAddressTable_rowreq_ctx * rowreq_ctx)
{
    DEBUGMSGTL(("verbose:ipAddressTable:ipAddressTable_row_prep",
                "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:390:o: Prepare row for request.
     * If populating row data was delayed, this is the place to
     * fill in the row for this request.
     */

    return MFD_SUCCESS;
}                               /* ipAddressTable_row_prep */

/** @} */