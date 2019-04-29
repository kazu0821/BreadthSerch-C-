#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>
#include <string>


#define BUG (cout << "NO BUGS!\n")


using namespace std;

void bfs (vector<int> alists[], int size, int start, int target);
void loadFlights(vector<int> flights[], string cityList[],int size, string fileName);
int removeDups(string list[], int max);
int partition(string arr[],int low, int high);
void quickSort(string arr[], int low, int high);
int bin2(string *list, int start, int end,string target);
int binarySearch(string *list,int end, string target);
int loadFile(string cityList[], int size, string fileName);
void bfs (vector<int> alists[], int size, int start, int target, string list[]);
bool findCity(string list[],int size,string target);
int enterDestination(string list[], int size);
int enterDepature(string list[], int size);
void printPath(int parents[], int size, int startv, int endv,string list[]);



int main() {


    const int MAXCITIES =1000;
    string cities[MAXCITIES];

    string repeat ="y";

    int fromInt, toInt;
    vector<int> adjacencyList[MAXCITIES];




    int numCities = loadFile(cities, MAXCITIES,"/Users/kazukikanke/CLionProjects/Shortestflight/connections.txt");
    loadFlights(adjacencyList,cities, numCities,"/Users/kazukikanke/CLionProjects/Shortestflight/connections.txt");


    //cout << "Please enter a departing city name : " << endl;



    quickSort(cities, 0, numCities);

    numCities = removeDups(cities, numCities);



    while(repeat != "n"){

        fromInt = enterDepature(cities, numCities);
        toInt = enterDestination(cities, numCities);
        bfs(adjacencyList,numCities, fromInt, toInt, cities);
        getline (cin, repeat);
        cout << endl;

    }

}
int loadFile(string cityList[], int size, string fileName){
    int i=0;
    ifstream  file(fileName.c_str());//ifstream is that input file into fileName

    //ofstream is output file

    if(!file){
        cout<< "Cannot open file"<< endl;
    }

    while(file && i < size){
        string str;
        getline(file,str);

        if(str != ""){
            cityList[i] = str.substr(7);//str is 文字列から指定された位置から指定された長さまでの文字列を取得する関数
            i++;
        }
    }
    file.close();
    return i;
}


void loadFlights(vector<int> flights[], string cityList[],int size, string fileName){
    ifstream file(fileName.c_str());
    if(!file){
        cout<< "Cannot open file"<< endl;
    }
    string s;
    int from, dest;
    getline(file, s);
    while(file && s!= ""){

        if(s.substr(0,4)== "From"){

            from = binarySearch(cityList,size, s.substr(7));

            getline(file,s);

            while(s != "" && s.substr(0,4) != "From"){
                flights[from].push_back(dest);
                getline(file,s);
            }

        }
    }
    file.close();

}


void printPath(int parents[], int size, int startv, int endv,string list[]){
    if (endv != startv){
        printPath(parents,size, startv, parents[endv],list);
    }
    cout << list[endv] << endl;
}


void bfs (vector<int> alists[], int size, int start, int target, string list[]){

    int * parents = new int[size];
    for (int i =0;i < size; i++) parents[i] =-1;
    parents[start] =start;
    queue<int> q;
    q.push(start);
    bool found = false;
    while(!q.empty() && !found){
        int v = q.front();
        if(v == target)
            found = true;

        else {
            for (int i =0; i < alists[v].size(); i++){
                int w = alists[v][i];
                if(parents[w] == -1){
                    parents[w]= v;
                    q.push(w);
                }
            }
        }
        if(found){
            cout << endl << "Route to Destination: " << endl;
            printPath(parents,size,start, target, list);
        }
        else
            cout << endl<< " There are no flights from the selected depart City" << endl;
            cout << endl;

        delete[] parents;
    }


}


int removeDups(string list[], int max){
    int i=0, k =0;
    while(i < max){
        if(i < max - 1 && list[i] == list[i+1])// remove dps
                i++;
        else{
            list[k] = list[i];// if it is not dups, move to next array
            k++;i++;
        }
    }
    for(int j=k;j<max;j++){
        list[j]="";
    }
    return k;

}

int binarySearch(string *list,int end, string target){

    return bin2(list,0,end-1,target);
}


int bin2(string *list, int start, int end,string target){
    int mid =(start + end)/2;
    if(start > end){
        return -1;
    }
    //test mid
    if(list[mid] == target){
        return mid;
    }
    else if (list[mid] < target){

       return  bin2(list, mid+1, end, target);
    }
    else{
        return bin2(list,start,mid-1, target);
    }

}



bool findCity(string list[],int size,string target){
    bool found = false;
    for(int i=0; i < target.length(); i++){
        char c = tolower(target[i]);
        target[i] =c;
    }
    string fromSearch;
    size_t foundIndex;
    for(int i=0; i <size; i++){
        fromSearch = list[i];

        for(int j=0;j<fromSearch.length();j++){
            char c = tolower(fromSearch[j]);
            fromSearch[j]=c;
        }
        foundIndex =fromSearch.find(target);
        if(foundIndex != string::npos){
            cout << i<< " " << list[i] << endl;
            found =true;
        }
    }
    return found;
}



int enterDepature(string list[], int size){
    string fromCity;
    int fromInt;
    bool cityFound;
    cout << "Please enter a departing city name: ";
    getline(cin, fromCity);
    cityFound = findCity(list,size,fromCity);
    while(!cityFound){
        cout << "Not found. "<< endl;
        cout << "Please enter a departing city name: ";
        getline(cin, fromCity);
        cityFound = findCity(list, size, fromCity);

    }
    cout << "Please Enter departing city Number: " << endl;
    cin>> fromInt;
    cin.ignore();

//    while(fromInt < 0 || fromInt >139){
//        cout << "Please Enter departing city number(0-139): " << endl;
//        cin >> fromInt;
//        cin.ignore();
//    }

    return fromInt;

}


int enterDestination(string list[], int size){
    string toCity;
    bool cityFound;
    int toInt;
    cout << "Please enter a destination city: " << endl;

    getline(cin, toCity);
    cityFound = findCity(list, size, toCity);

    while(!cityFound){
        cout << "Not Found" << endl;
        cout << "Please enter a destination city: ";
        getline(cin, toCity);
        cityFound = findCity(list, size,toCity);
    }
    cout << "Please select a destination by entering a number from the list above: ";
    cin >> toInt;
    cin.ignore();

   // cout <<"Selected Destination: " << cityFound << " " << toCity << endl;

    while(toInt < 0|| toInt > 139){
        cout << "Please Enter Destination City Number (0 -139)";
        cin >> toInt;
        cin.ignore();
    }
    return toInt;

}








int partition(string arr[],int low, int high){

    string pivot =arr[high];
    int i = (low -1);


    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            string t =arr[i];
            arr[i] = arr[j];//Swap the array
            arr[j] =t;
            //swap(&arr[i], &arr[j]);
        }
    }
    string temp =arr[i+1];
    arr[i+1] = arr[high];//Swap the array
    arr[high] =temp;

    //swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(string arr[], int low, int high) {
    if (low < high) {

        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);

    }
}









