#include <stdio.h>
#include <time.h>
#include <sys/sysinfo.h>
#include <math.h>


int main(int argc, char *argv[]) {
   printf("******************************\n");
   printf("*** ACO350 - Alissa Daniel ***\n");
   printf("***  System Info Utility   ***\n");
   printf("******************************\n\n");
   
   //creation of time struct
   struct tm *dateTime;
   time_t currentTime;
   time(&currentTime);
   dateTime = localtime(&currentTime);
   
   //matches number of the day of the week to its name
   char *daysOfWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
   char *weekday = daysOfWeek[dateTime -> tm_wday];
   
   //matches number of the month to its corresponding name
   char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
   char *month = months[dateTime -> tm_mon];
   
   //prints the current date
   printf("Current Date: %s, %s %d, %d\n", weekday, month, dateTime -> tm_mday,dateTime -> tm_year+1900);
   //prints the current time
   printf("Current Time: %d:%d:%d\n", dateTime->tm_hour, dateTime->tm_min, dateTime->tm_sec);


   //creation of sysinfo struct
   struct sysinfo my_sysinfo;
   sysinfo(&my_sysinfo);
   
   //prints the time in seconds and days since last reboot
   double days = my_sysinfo.uptime / 86400.00;
   printf("Last Reboot : %ld seconds (%.2f days)\n", my_sysinfo.uptime, days);
   
   //prints the number of processors configured, available, and current processes
   printf("\nNumber of processors configured: %d\n", get_nprocs_conf());
   printf("Number of processors available : %d\n", get_nprocs());
   printf("Number of current processes    : %d\n", my_sysinfo.procs);

   //prints various memory information using the sysinfo struct
   printf("\nTotal usable memory size: %.3f GB\n", my_sysinfo.totalram / pow(10, 9));

   printf("Available memory size   : %.3f GB\n", my_sysinfo.freeram / pow(10, 9));
   
   printf("Amount of shared memory : %.2f MB\n", my_sysinfo.sharedram  / pow(10, 6));

   printf("Memory used by buffers  : %.2f MB\n", my_sysinfo.bufferram / pow(10, 6));
   
   printf("Total swap space size   : %.2f MB\n", my_sysinfo.totalswap / pow(10, 6));
   
   printf("Swap space available    : %.2f MB\n", my_sysinfo.freeswap / pow(10, 6));
   return 0;
}

