/*
 * Copyright (c) 2004-2007 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2005 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart, 
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
 * Copyright (c) 2008      Cisco Systems, Inc.  All rights reserved.
 * Copyright (c) 2008-2014 University of Houston. All rights reserved.
 * $COPYRIGHT$
 * 
 * Additional copyrights may follow
 * 
 * $HEADER$
 *
 * These symbols are in a file by themselves to provide nice linker
 * semantics.  Since linkers generally pull in symbols by object
 * files, keeping these symbols as the only symbols in this file
 * prevents utility programs such as "ompi_info" from having to import
 * entire components just to query their version and parameters.
 */

#include "ompi_config.h"
#include "fcoll_static.h"

#include "mpi.h"
#include "ompi/mca/fcoll/fcoll.h"
#include "fcoll_static.h"

/*
 * Public string showing the fcoll ompi_static component version number
 */
const char *mca_fcoll_static_component_version_string =
    "Open MPI static collective MCA component version " OMPI_VERSION;

/*
 * Global variables
 */
int mca_fcoll_static_priority = 10;

/*
 * Local function
 */
static int static_register(void);

/*
 * Instantiate the public struct with all of our public information
 * and pointers to our public functions in it
 */
mca_fcoll_base_component_2_0_0_t mca_fcoll_static_component = {

    /* First, the mca_component_t struct containing meta information
     * about the component itself */

    {
     MCA_FCOLL_BASE_VERSION_2_0_0,

     /* Component name and version */
     "static",
     OMPI_MAJOR_VERSION,
     OMPI_MINOR_VERSION,
     OMPI_RELEASE_VERSION,
     .mca_register_component_params = static_register,
    },
    {
        /* The component is checkpoint ready */
        MCA_BASE_METADATA_PARAM_CHECKPOINT
    },

    mca_fcoll_static_component_init_query,
    mca_fcoll_static_component_file_query,
    mca_fcoll_static_component_file_unquery
};


static int
static_register(void)
{
    mca_fcoll_static_priority = 10;
    (void) mca_base_component_var_register(&mca_fcoll_static_component.fcollm_version,
                                           "priority", "Priority of the static fcoll component",
                                           MCA_BASE_VAR_TYPE_INT, NULL, 0, 0,
                                           OPAL_INFO_LVL_9,
                                           MCA_BASE_VAR_SCOPE_READONLY, &mca_fcoll_static_priority);

    return OMPI_SUCCESS;
}
