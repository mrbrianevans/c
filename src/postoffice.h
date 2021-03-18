#ifndef __POSTOFFICE_H
#define __POSTOFFICE_H
#include "queue.h"
#include "parameters.h"
#include "servicePoints.h"
#include "iteration.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "statistics.h"

/**
 * Runs a single simulation, appending the results to multiple statistics
 * @return int status code where 0=SUCCESS, -1=file error, -2=memory fault
 */
extern int singleSimulation(INPUT_OPTIONS *, FILE *, MULTIPLE_STATISTICS *);

#endif /*__POSTOFFICE_H*/
