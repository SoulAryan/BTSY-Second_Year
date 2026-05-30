#include <stdio.h>
// Global Variables
int rc = 0;      // Reader Count
int mutex = 1;   // Semaphore for Reader Count
int db = 1;      // Semaphore for Database
// DOWN Operation for mutex
void down_mutex()
{
    while(mutex == 0)

    mutex = 0;
}
// UP Operation for mutex
void up_mutex()
{
    mutex = 1;
}
// DOWN Operation for database
void down_db()
{
    while(db == 0)

    db = 0;
}
// UP Operation for database
void up_db()
{
    db = 1;
}
// Reader Function
void Reader(int id)
{
    printf("\nReader %d is Entering\n", id);

    down_mutex();

    rc = rc + 1;
    // First Reader locks database
    if(rc == 1)
    {
        down_db();
    }

    up_mutex();
    // Critical Section
    printf("Reader %d is Reading\n", id);

    down_mutex();

    rc = rc - 1;

    // Last Reader unlocks database
    if(rc == 0)
    {
        up_db();
    }
    up_mutex();

    printf("Reader %d is Exiting\n", id);
}
// Writer Function
void Writer(int id)
{
    printf("\nWriter %d is Entering\n", id);
    down_db();
    // Critical Section
    printf("Writer %d is Writing\n", id);
    up_db();
    printf("Writer %d is Exiting\n", id);
}
int main()
{
    Reader(1);
    Reader(2);
    Writer(1);
    Reader(3);
    return 0;
}