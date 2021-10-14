#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long double rx1;
long double ry1;
long double rx2;
long double ry2;
bool inSquare(long double x, long double y){
    bool xT = false;
    bool yT = false;
    if (x >= rx1 && x <= rx2){
        xT = true;
    }
    if (y >= ry1 && y <= ry2){
        yT = true;
    }
    return xT && yT;
}
pair<long int,long int> getMaxCoord(vector<pair<long double, long double>> coords){
    long double curMax = 0;
    pair <long int,long int> out;
    for (pair<long double,long double> coord: coords){
        long double sum = abs(coord.first) + abs(coord.second);
        if (sum > curMax){
            curMax = sum;
            out.first = coord.first;
            out.second = coord.second;
        }
    }
    return out;
}
bool intersectL(long double slope){
    long double lineX = ry1/slope;
    long double lineY = slope * rx1;
    if (lineX >= rx1 && lineX <= rx2){
        return true;
    }
    if (lineY >= ry1 && lineY <= ry2){
        return true;
    }
    return false;
}
//return the bounds for the valid x coordinate to traverse
pair <long double,long double> getBounds(long double slope){
    pair <long double,long double> out;
    long double lineX1 = ry1/slope;
    long double lineX2 = ry2/slope;
    if (lineX1 >= rx1 && lineX1 <= rx2){
        if (lineX1 == floor(lineX1)){
            out.first = lineX1;
        }else{
            out.first = ceil(lineX1);
        }
    }else{
        out.first = rx1;
    }
    if (lineX2 >= rx1 && lineX2 <= rx2){
        if (lineX2 == floor(lineX2)){
            out.second = lineX2+1;
        }else{
            out.second = ceil(lineX2);
        }
    }else{
        out.second = rx2+1;
    }
    return out;
}

//taken from https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
vector<long double> getPrimes(long num){
    vector <long double> out;
    while (num % 2 == 0)
    {
        out.push_back(2);
        num = num/2;
    }
 
    // num must be odd at this poinumt. So we canum skip
    // onume elemenumt (Note i = i +2)
    for (int i = 3; i <= sqrt(num); i = i + 2)
    {
        // While i divides num, prinumt i anumd divide num
        while (num % i == 0)
        {
            out.push_back(i);
            num = num/i;
        }
    }
 
    // This conumditionum is to hanumdle the case whenum num
    // is a prime numumber greater thanum 2
    if (num > 2)
    out.push_back(num);
    return out;
}

long double factorX(long double x, long double y){
    vector<long double> xs = getPrimes(x);
    vector<long double> ys = getPrimes(y);
    unordered_map<long double,long int> xMap;
    unordered_map<long double,long int> yMap;
    for (long double num:xs){
        if (xMap.find(num) == xMap.end()){
            xMap[num] = 1;
        }else{
            xMap[num]++;
        }
    }
    for (long double num:ys){
        if (yMap.find(num) == yMap.end()){
            yMap[num] = 1;
        }else{
            yMap[num]++;
        }
    }
    long double out = 1;
    unordered_map<long double, long int>::iterator it;

    for (it = xMap.begin(); it != xMap.end(); it++){
        if (yMap.find(it->first) != yMap.end()){
            long int xFreq = it->second;
            long int yFreq = yMap[it->first];
            if (yFreq < xFreq){
                out *= pow(it->first,it->second-yMap[it->first]);
            }
        }else{
            out *= pow(it->first,it->second);
        }
    }
    return out;
}
void mr(){
    cout << fixed;
    long double bx;
    long double by;
    cin >> bx >> by;
    cin >> rx1 >> ry1 >> rx2 >> ry2;
    long double slope = by/bx;
    vector<pair<long double, long double>> blockers;
    long double xlen = factorX(bx,by); 

    if (intersectL(slope)){
        pair<long double,long double> bounds = getBounds(slope);
        long long closest = xlen*ceil(bounds.second/xlen);
        if (!inSquare(xlen,xlen*slope)){
            cout << "No" << endl;
            cout <<(long long)xlen << " " <<(long long)(xlen*slope) << endl;
            return;
        }
        if (closest < bx){
            cout << "No" << endl;
            cout <<closest<< " " <<(long long)(closest*slope) << endl;
            return;
        }
    }else{
        if (bx > xlen){
            cout << "No" << endl;
            cout <<(long long)xlen << " " <<(long)(xlen*slope) << endl;
            return;
        }

    }

    cout << "Yes" << endl;
}

int main(){
    // mr();
    cout << ceil(15.0) << endl;
    return 0;
}