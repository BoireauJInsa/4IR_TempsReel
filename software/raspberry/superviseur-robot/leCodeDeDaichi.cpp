// Déclaration des priorités des taches

#define PRIORITY_WATCHCOMM 17

/**************************************************************************************/
/* Tasks creation                                                                     */
/**************************************************************************************/

if (err = rt_task_create(&th_watchComm, "th_watchComm", 0, PRIORITY_WATCHCOMM, 0))
{
    cerr << "Error task create: " << strerror(-err) << endl
         << flush;
    exit(EXIT_FAILURE);
}

/**
 * @brief Démarrage des tâches
 */

if (err = rt_task_start(&th_watchComm, (void (*)(void *)) & Tasks::WatchComm, this))
{
    cerr << "Error task start: " << strerror(-err) << endl
         << flush;
    exit(EXIT_FAILURE);
}

/**
 * @brief Thread supervising communication between robot and supervisor.
 */
void Tasks::OpenComRobot(void *arg)
{
    int status;
    int err;
    int counter;
    int maxCounter = 3;
    String receivedMsg

            cout
        << "Start " << __PRETTY_FUNCTION__ << endl
        << flush;

    // Synchronization barrier (waiting that all tasks are starting)
    rt_sem_p(&sem_barrier, TM_INFINITE);

    /**************************************************************************************/
    /* The task openComRobot starts here                                                  */
    /**************************************************************************************/

    counter = 0;
    while (1)

    {

        //when message received
        if (msgRcv->CompareID(MESSAGE_ANSWER_ROBOT_TIMEOUT))
        {
            counter += 1;
            if (counter > maxCounter)
            {
                cout << "ERROR communication between robot and supervisor lost." << endl
                     << flush;
            }
        if(!msgRcv->CompareID(MESSAGE_ANSWER_ROBOT_TIMEOUT))
        {
            counter = 0;
        }
        }
    }
}
