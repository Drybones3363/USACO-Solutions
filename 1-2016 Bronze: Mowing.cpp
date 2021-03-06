//http://www.usaco.org/index.php?page=viewproblem2&cpid=593

#include<fstream>
#include<vector>

using namespace std;

int get_inc(char d) { //get increment of position function
    if (d=='N') {return -10000;} else if (d=='S') {return 10000;}
    else if (d=='W') {return 1;} else if (d=='E') {return -1;}
    else {return 0;} //basically translates compass positions to integers the compiler can use
}
    	
int main() {
	ifstream cin ("mowing.in");
	ofstream cout ("mowing.out");
    int ret = -1; //the return value
    int n;
    cin >> n; //how many directions??
    vector<int> tbl; //vector for positions he has walked
    vector<int> timetbl; //vector for the time he walked those positions
    int p = 0; //variable to store his current position
    int t = 0; //variable to store the current time
    for (int i=0;i<n;i++) { //for every direction he went do:
    	char d; //direction
    	cin >> d;
    	int s; //number of steps he took in direction 'd'
    	cin >> s;
    	int inc = get_inc(d); //translate d to an integer
    	for (int e=0;e<s;e++) { //for every step, check if he cut that grass before
    		p+=inc; //increment position based on the direction he's going
    		for (int r=0;r<tbl.size();r++) { //check all positions to see if he mowed it before
    			if (tbl.at(r) == p) { //if he mowed it before then:
    				if (ret == -1 || t-timetbl.at(r) < ret) { 
    					ret = t-timetbl.at(r);
    					/*if the time it took to have the grass grow back is less than the time 
    					we have from before then set ret as this time since it is now the maximum
    					value x can be so he doesn't mow over already cut grass*/
    				}
    			}
    		}
    		tbl.push_back(p); //put current position in vector for later use
    		timetbl.push_back(t); //put current time in vector for later use
    		t++; //increment time by 1
    	}
    }
    cout << ret;
}
