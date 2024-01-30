// Include the DAG.h header file to access the DAG class
#include "DAG.h"

// Function to schedule jobs on machines to minimize the overall execution time
// Parameters:
//   - graph: A reference to the DAG object representing the workflow
//   - numMachine: The number of machines available for scheduling
// Returns:
//   - The minimum overall execution time achieved by the scheduling
int schedule(DAG &graph, int numMachine);
