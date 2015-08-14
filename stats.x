/**
* stats.x: Remote message printing protocol
*/

struct DATA {
              int array[11];
	      int arr[10];	
       }; 

program STATSPROG {

      version STATSVERS {

            int search(DATA, int) = 1;
	    int zero(DATA, int)=2;
	    int sum(DATA)=3;
	    int median(DATA)=4;
	    int average(DATA)=5;
	    int STDEV(DATA)=6;

      } = 1;

} = 0x20083001;
