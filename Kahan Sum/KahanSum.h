#include <iostream>
#include <vector>
using namespace std;
float kahanSum(vector<float> nums);
float directSum(vector<float> nums);
int main()
{
vector<float> numbers;
for (float i = 0.0; i < 10000.0; i += 0.02){
numbers.push_back(i);}
printf("Direct Sum: %.2lf", directSum(numbers));
printf("\nKahan Sum: %.2lf", kahanSum(numbers));
getchar();
return 0;
}
float directSum(vector<float> nums)
{
float dSum = 0.0f;
vector<float>::iterator iter;
for (iter = nums.begin(); iter != nums.end(); iter++){
dSum += *iter;}
return dSum;
}
float kahanSum(vector<float> nums)
{
float kSum = 0.0f,com = 0.0f;
vector<float>::iterator iter;
for (iter = nums.begin(); iter != nums.end(); iter++)
{
float v = *iter + com;
float next = kSum + v;
com = v - (next - kSum);
kSum = next;
}
return kSum;
}