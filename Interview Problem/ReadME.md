## #1 hello world  
### Problem Instruction  
> 请完成函数f，返回"hello world"字符串。  
### Problem Solving Techniques and Ideas  
Basic testing 
```c++=
#include <string>
std::string f()
{
    std::string helloWorld = "hello world";
    return helloWorld;
}
```
### Result
![](https://i.imgur.com/fhFMovY.png)

## #2 排序  
### Problem Instruction  
> 请完成函数f，对input按升序排序，然后返回排序后的字符串，数字间用1个空格隔开。例如：输入数组是[2,1]，输出则为"1 2"  
### Problem Solving Techniques and Ideas  
Utilize Quick Sort for such problem
### Code  
```c++=
#include <vector>
#include <string>
using namespace std;
// Swap function
void swap(vector<int>& input,int i,int j){
    int tempt = input[i];
    input[i] = input[j];
    input[j] = tempt;
}
// Partition function
int partition(vector<int>& input,int front,int back){
    int i = front - 1;
    int piv = input[back];
    for(int j = front; j < back; j++){
        if(piv > input[j]){
            i++;
            swap(input, i, j);
        }
    }
    i++;
    swap(input, i, back);
    return i;
}
// QuickSort function
void quickSort(vector<int>& input, int front, int back){
    if(front<back){
        int m = partition(input, front, back);
        quickSort(input, front, m-1);
        quickSort(input, m+1, back);
    }
}
std::string f(const std::vector<int>& input)
{      
    // Due to const, copy a input
    vector<int> inputCopy = input;
    quickSort(inputCopy, 0, inputCopy.size() -1);
    // Concatenate the string
    string ans;
    for(int i = 0; i < inputCopy.size() - 1; i++){
        ans+= to_string(inputCopy[i]);
        ans+= " ";
    }
    ans+= to_string(inputCopy[inputCopy.size()-1]);
    return ans;
}
```
### Result
![](https://i.imgur.com/oTRRPct.png)

## #3 算牌型
### Problem Instruction
> 请完成函数f，输入的5个数字代表5张牌，含义如下：
0x102,0x103,0x104,0x105,0x106,0x107,0x108,0x109,0x10a,0x10b,0x10c,0x10d,0x10e分别代表方块2,3,4,5,6,7,8,9,10,J,Q,K,A
0x202,0x203,0x204,0x205,0x206,0x207,0x208,0x209,0x20a,0x20b,0x20c,0x20d,0x20e分别代表梅花2,3,4,5,6,7,8,9,10,J,Q,K,A
0x302,0x303,0x304,0x305,0x306,0x307,0x308,0x309,0x30a,0x30b,0x30c,0x30d,0x30e分别代表红桃2,3,4,5,6,7,8,9,10,J,Q,K,A
0x402,0x403,0x404,0x405,0x406,0x407,0x408,0x409,0x40a,0x40b,0x40c,0x40d,0x40e分别代表黑桃2,3,4,5,6,7,8,9,10,J,Q,K,A
返回的数字含义如下：
1、皇家同花顺：如果花色一样，数字分别是10,J,Q,K,A
2、同花顺：如果花色一样，数字是连续的，皇家同花顺除外，例如[0x109,0x10a,0x10b,0x10c,0x10d],[0x10e,0x102,0x103,0x104,0x105]
3、金刚：其中4张牌数字一样
4、葫芦：其中3张牌数字一样，另外2张牌数字一样
5、同花：花色一样，数字不连续
6、顺子：数字是连续，花色不一样
7、三条：其中3张牌数字一样，另外2张牌数字不一样
8、两对：其中2张牌数字一样，另外其中2张牌数字一样，最后一张数字不一样
9、一对：其中2张牌数字一样，另外数字不一样
10、高牌：什么都不是
### Problem Solving Techniques and Ideas  
1. Utilize the concept of class to encapsulate the properities of each card  
2. Each question has an individual function to determine its correctness  
3. f function has the following process  
    1. Determine each card from its Hex form and store into a vector with Classes of Cards  
    2. Unordered Map stores each occurence of each kind of number   
    3. Test each function from IsRoyalFlush to HighCard  

### Code
```c++=
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// Define Every Possibilities
#define RoyalFlush      1;  //皇家同花顺
#define StraightFlush   2;  //同花顺
#define FourKind        3;  //金刚
#define FullHouse       4;  //葫芦
#define Flush           5;  //同花
#define Straight        6;  //顺子
#define ThreeKind       7;  //三条
#define TwoPairs        8;  //两对
#define Pair            9;  //一对
#define Highcard       10;  //高牌

#define Diamonds       21;  //方塊
#define Clubs          22;  //梅花
#define Hearts         23;  //紅桃
#define Spades         24;  //黑桃
// Define Card Class
class Card{
    public:
        int num;
        int suit;
};
// Define functions
void swapCard(vector<Card>&,int,int);
bool IsRoyalFlush(vector<Card>);
bool IsStraightFlush(vector<Card>);
bool IsFourKind(int);
bool IsFullHouse(int,int);
bool IsFlush    (vector<Card>);
bool IsStraight (vector<Card>);
bool IsThreeKind(int,int);
bool IsTwoPairs (int,int);
bool IsPair     (int,int);
// Return function
int f(const std::vector<int>& input)
{
    // Due to const, copy a input
    vector<int> inputCopy = input;
    // sort(inputCopy.begin(), inputCopy.end());
    vector<Card> VCard;
    // Transfer Hex Card to Class Card
    for(int i = 0; i < inputCopy.size(); i++){
        Card Ocard;
        Ocard.suit = (inputCopy[i] / 0x100) + 20;
        int num = inputCopy[i] - (Ocard.suit - 20) * 0x100;
        if(num == 14) Ocard.num = 1;
        else Ocard.num = num;
        VCard.push_back(Ocard);
    }
    // Sort my hand 
    // Where to put A? A defalut the leftest, simple bubble sort
    for(int i = 0; i < VCard.size(); i++){
        for(int j = 0; j < VCard.size()-1; j++){
            if(VCard[j].num > VCard[j+1].num){
                swapCard(VCard,j,j+1);
            }
        }
    }
    unordered_map<int,int> umap;
    for(int i = 0; i < VCard.size(); i++){
        if(umap.find(VCard[i].num) != umap.end()){
            umap[VCard[i].num] += 1;
        }else umap[VCard[i].num] = 1;
    }
    // Calculate the Max value in umap
    int currentMax = 0;
    int TwoPairsNum = 0;
    for(auto it = umap.cbegin(); it != umap.cend(); ++it){
        if (it ->second > currentMax) currentMax = it->second;
        if (it ->second == 2) TwoPairsNum+=1;
    }
    // Each function return
    if(IsRoyalFlush(VCard)){
        return RoyalFlush;
    }
    else if(IsStraightFlush(VCard)){
        return StraightFlush;
    }
    else if(IsFourKind(currentMax)) {
        return FourKind;
    }
    else if(IsFullHouse(currentMax,TwoPairsNum)) {
        return FullHouse;
    }
    else if(IsFlush(VCard)) {
        return Flush;
    }
    else if(IsStraight(VCard)) {
        return Straight;
    }
    else if(IsThreeKind(currentMax, TwoPairsNum)) {
        return ThreeKind;
    }
    else if(IsTwoPairs(currentMax, TwoPairsNum)) {
        return TwoPairs;
    }
    else if(IsPair(currentMax, TwoPairsNum)) {
        return Pair;
    }
    else{
        return Highcard;
    }
}
void swapCard(vector<Card>& VCard,int i,int j){
    Card temptC = VCard[i];
    VCard[i] = VCard[j];
    VCard[j] = temptC;
}
bool IsRoyalFlush(vector<Card> VCard){
    if(IsStraightFlush(VCard) && IsStraight(VCard) ){
        if(VCard[0].num == 1 && VCard[VCard.size() - 1].num == 13){
            return true;
        }
        else return false;
    }
    else return false;
}
bool IsStraightFlush(vector<Card> VCard){
    bool ans = 1;
    int cmpSuit = VCard[0].suit;
    if(IsStraight(VCard)){
        for(int i = 0; i < VCard.size(); i++){
            if(cmpSuit != VCard[i].suit){
                ans = 0;
            }
        }
    }else ans = 0;
    return ans;
}
bool IsStraight(vector<Card> VCard){
    int delta = 0;
    bool KFlag = 0;
    bool AFlag = 0;
    for(int i = 0; i < VCard.size() - 1; i++){
        delta += VCard[i+1].num - VCard[i].num;
        if(VCard[i].num == 1) AFlag = 1;
        if(VCard[i+1].num == 13) KFlag = 1;                                                                                                                                 
    }
    if(KFlag == 1 && AFlag == 1){
        delta = 1; // K and A 's delta
        for(int i = 1; i < VCard.size() - 1; i++){
            delta += VCard[i+1].num - VCard[i].num;                                                                                                                              
        }
    }
    if(delta == 4) return true;
    else return false;
}
bool IsFourKind(int currentMax){
    if(currentMax == 4) return 1;
    else return 0;
}
bool IsFullHouse(int currentMax, int TwoPairsNum){
    if(currentMax == 3 && TwoPairsNum == 1) return 1;
    else return 0;
}
bool IsFlush    (vector<Card> VCard){
    int CheckSuit = VCard[0].suit;
    for(int i = 1; i < VCard.size(); i++) if(CheckSuit != VCard[i].suit) return 0;
    return 1;
}
bool IsThreeKind(int currentMax, int TwoPairsNum){
    if(currentMax == 3 && TwoPairsNum == 0) return 1;
    else return 0;
}
bool IsTwoPairs (int currentMax, int TwoPairsNum){
    if(currentMax == 2 && TwoPairsNum == 2) return 1;
    else return 0;
}
bool IsPair     (int currentMax, int TwoPairsNum){
    if(currentMax == 2 && TwoPairsNum == 1) return 1;
    else return 0;
}
```
### Result
![](https://i.imgur.com/EARRNXx.png)
## #4 赖子算牌型  
### Problem Instruction  
>x102,0x103,0x104,0x105,0x106,0x107,0x108,0x109,0x10a,0x10b,0x10c,0x10d,0x10e分别代表方块2,3,4,5,6,7,8,9,10,J,Q,K,A
0x202,0x203,0x204,0x205,0x206,0x207,0x208,0x209,0x20a,0x20b,0x20c,0x20d,0x20e分别代表梅花2,3,4,5,6,7,8,9,10,J,Q,K,A
0x302,0x303,0x304,0x305,0x306,0x307,0x308,0x309,0x30a,0x30b,0x30c,0x30d,0x30e分别代表红桃2,3,4,5,6,7,8,9,10,J,Q,K,A
0x402,0x403,0x404,0x405,0x406,0x407,0x408,0x409,0x40a,0x40b,0x40c,0x40d,0x40e分别代表黑桃2,3,4,5,6,7,8,9,10,J,Q,K,A
0x50f代表小王
0x610代表大王
小王大王可以变为任意牌，要求算出小王大王变换后最大牌型
返回的数字含义如下：
1、皇家同花顺：如果花色一样，数字分别是10,J,Q,K,A
2、同花顺：如果花色一样，数字是连续的，皇家同花顺除外
3、金刚：其中4张牌数字一样
4、葫芦：其中3张牌数字一样，另外2张牌数字一样
5、同花：花色一样，数字不连续
6、顺子：数字是连续，花色不一样
7、三条：其中3张牌数字一样，另外2张牌数字不一样
8、两对：其中2张牌数字一样，另外其中2张牌数字一样，最后一张数字不一样
9、一对：其中2张牌数字一样，另外数字不一样
10、高牌：什么都不是  
### Problem Solving Techniques and Ideas  
Basic idea is similar to the previous problem but with the following constraints  

| Function        | Joker = 1                    | Joker = 2 |
| --------------- | ---------------------------- | -------- |
| Royal Flush     | Use Subtract to compare      | Use Subtract to compare         |
| Straight Flush  | Same Suit && Difference 4 or 3  | Same Suit && Difference 4 or 3 or 2   |
| Four of a Kind  | Three Cards the same rank | Two Cards the same rank   |
| Full House      |Three of a kind or two pairs|Three of a kind or one pairs|
| Flush           | non-joker same suit  | non-joker same suit |
| Straight        | Difference 4 or 3|  Difference 4 or 3 or 2 |
| Three of a Kind | Two Cards the same rank | Must be Three of a Kind |
| Two Pairs       | Two cards the same rank | x |
| Pair            | Must have a pair  | x |


```c++=
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define RoyalFlush      1  //皇家同花顺
#define StraightFlush   2  //同花顺
#define FourKind        3  //金刚
#define FullHouse       4  //葫芦
#define Flush           5  //同花
#define Straight        6  //顺子
#define ThreeKind       7  //三条
#define TwoPairs        8  //两对
#define Pair            9  //一对
#define Highcard       10  //高牌

#define Diamonds       21  //方塊
#define Clubs          22  //梅花
#define Hearts         23  //紅桃
#define Spades         24  //黑桃
#define Joker          25  //Joker

class Card{
    public:
        int num;
        int suit;
};
void swapCard(vector<Card>&,int,int);
bool IsRoyalFlush(vector<Card>,unordered_map<int,int>);
bool IsStraightFlush(vector<Card>,unordered_map<int,int>);
bool IsFourKind(int,unordered_map<int,int>);
bool IsFullHouse(int,int,unordered_map<int,int>);
bool IsFlush    (vector<Card>,unordered_map<int,int>);
bool IsStraight (vector<Card>, unordered_map<int,int>);
bool IsThreeKind(int,int,unordered_map<int,int>);
bool IsTwoPairs (int,int,unordered_map<int,int>);
bool IsPair     (int,int,unordered_map<int,int>);

int f(const std::vector<int>& input)
{
    // Due to const, copy a input
    vector<int> inputCopy = input;
    // sort(inputCopy.begin(), inputCopy.end());
    vector<Card> VCard;
    for(int i = 0; i < inputCopy.size(); i++){
        Card Ocard;
        Ocard.suit = (inputCopy[i] / 0x100) + 20;
        int num = inputCopy[i] - (Ocard.suit - 20) * 0x100;
        if(num == 14) {
            Ocard.num = 1;
        }else if(inputCopy[i] == 0x50f || inputCopy[i] == 0x610){
            Ocard.num = 0;
            Ocard.suit = Joker;
        }
        else {
            Ocard.num = num;
        }
        VCard.push_back(Ocard);
    }
    // Sort my hand 
    // Where to put A? A defalut the leftest
    for(int i = 0; i < VCard.size(); i++){
        for(int j = 0; j < VCard.size()-1; j++){
            if(VCard[j].num > VCard[j+1].num){
                swapCard(VCard,j,j+1);
            }
        }
    }
    unordered_map<int,int> umap;
    for(int i = 0; i < VCard.size(); i++){
        if(umap.find(VCard[i].num) != umap.end()){
            umap[VCard[i].num] += 1;
        }else umap[VCard[i].num] = 1;
    }
    // Calculate the Max value in umap
    int currentMax = 0;
    int TwoPairsNum = 0;
    for(auto it = umap.cbegin(); it != umap.cend(); ++it){
        // Make sure that two Joker does not become currentMax;
        if (it ->second > currentMax && it->first != 0) {
            currentMax = it->second;
        }
        if (it ->second == 2  && it->first != 0) {
            TwoPairsNum+=1;
        }
    }
    // Each function test
    if(IsRoyalFlush(VCard,umap)){
        return RoyalFlush;
    }
    else if(IsStraightFlush(VCard,umap)){
        return StraightFlush;
    }
    else if(IsFourKind(currentMax,umap)) {
        return FourKind;
    }
    else if(IsFullHouse(currentMax,TwoPairsNum,umap)) {
        return FullHouse;
    }
    else if(IsFlush(VCard,umap)) {
        return Flush;
    }
    else if(IsStraight(VCard,umap)) {
        return Straight;
    }
    else if(IsThreeKind(currentMax, TwoPairsNum,umap)) {
        return ThreeKind;
    }
    else if(IsTwoPairs(currentMax, TwoPairsNum,umap)) {
        return TwoPairs;
    }
    else if(IsPair(currentMax, TwoPairsNum,umap)) {
        return Pair;
    }
    else{
        return Highcard;
    }
}
void swapCard(vector<Card>& VCard,int i,int j){
    Card temptC = VCard[i];
    VCard[i] = VCard[j];
    VCard[j] = temptC;
}
bool IsRoyalFlush(vector<Card> VCard, unordered_map<int,int> umap){
    vector<int> checkData; // = {1,10,11,12,13};
    checkData.push_back(1);
    checkData.push_back(10);
    checkData.push_back(11);
    checkData.push_back(12);
    checkData.push_back(13);

    vector<int> VCardNum;
    for(int i = 0; i < VCard.size(); i++){
        VCardNum.push_back(VCard[i].num);
    }
    std::vector<int> result;
    std::set_difference(checkData.begin(),checkData.end(), VCardNum.begin(), VCardNum.end(),
        std::inserter(result, result.end()));
    if(IsStraightFlush(VCard,umap) && IsStraight(VCard,umap) && umap.find(0) == umap.end()){
        if(VCard[0].num == 1 && VCard[VCard.size() - 1].num == 13){
            return true;
        }
        else return false;
    }else if(umap[0] == 1){
        if (result.size() == 1) return true;
        else return false;
    }else if(umap[0] == 2){
         if (result.size() == 2) return true;
        else return false;
    }
    else return false;
}
bool IsStraightFlush(vector<Card> VCard,unordered_map<int,int> umap){
    bool ans = 1;
    int cmpSuit;
    for(int i = 0; i < VCard.size(); i++){
        if(VCard[i].suit != Joker){
            cmpSuit = VCard[i].suit;
            break;
        }
    }
    if(IsStraight(VCard,umap)){
        for(int i = 0; i < VCard.size(); i++){
            if((cmpSuit != VCard[i].suit) && (VCard[i].suit != Joker)){
                ans = 0;
            }
        }
    }else ans = 0;
    return ans;
}
bool IsStraight(vector<Card> VCard, unordered_map<int,int> umap){
    // Need to consider Joker by readjusting delta
    int delta = 0;
    bool KFlag = 0;
    bool AFlag = 0;
    bool JokerFlag = 0;
    if(umap.find(1)!=umap.end()) AFlag = 1;
    if(umap.find(13)!=umap.end()) KFlag = 1;
    if(umap.find(0)!=umap.end()) JokerFlag = 1;
    if(KFlag == 1 && AFlag == 1){ 
        delta = 1; // K and A 's delta
        for(int i = 1; i < VCard.size() - 1; i++){
            if(VCard[i+1].num != 0 && VCard[i].num != 0
                && VCard[i].num != 1 && VCard[i+1].num != 1){
                    delta += VCard[i+1].num - VCard[i].num;   
            }                                                                                                                            
        }
    }
    else {
        for(int i = 0; i < VCard.size() - 1; i++){
            if(VCard[i+1].num != 0 && VCard[i].num != 0){
                delta += VCard[i+1].num - VCard[i].num;   
            }                                                                                                                                  
        }
    }
    // Consider 1's 0  3 <= delta <=4
    if(delta == 4) {
        return true;
    }else if(umap[0] == 1 && (delta <= 4 && delta >=3)){
        return true;
    }else if(umap[0] == 2 && (delta <= 4 && delta >= 2)){
        return true;
    }
    else return false;
}
bool IsFourKind(int currentMax,unordered_map<int,int> umap){
    if(currentMax == 4) {
        return 1;
    }else if(currentMax == 3 && umap[0] == 1){
        return 1;
    }else if(currentMax == 2 && umap[0] == 2){
        return 1;
    }
    else return 0;
}
bool IsFullHouse(int currentMax, int TwoPairsNum,unordered_map<int,int> umap){
    if(currentMax == 3 && TwoPairsNum == 1) {
        return 1;
    }else if((currentMax == 3 || TwoPairsNum == 2) && umap[0] == 1){
        return 1;
    }else if((currentMax == 3 || TwoPairsNum == 1) && umap[0] == 2){
        return 1;
    }
    else return 0;
}
bool IsFlush    (vector<Card> VCard,unordered_map<int,int> umap){
    int CheckSuit;
    for(int i = 1; i < VCard.size(); i++){
        if(VCard[i].suit != Joker){
            CheckSuit = VCard[i].suit;
            break;
        }
    }
    for(int i = 1; i < VCard.size(); i++) if(CheckSuit != VCard[i].suit && VCard[i].suit != Joker) return 0;
    return 1;
}
bool IsThreeKind(int currentMax, int TwoPairsNum,unordered_map<int,int> umap){
    if(currentMax == 3 && TwoPairsNum == 0 && umap.find(0) == umap.end()){
        return 1;
    }else if (currentMax == 2 && umap[0] == 1){
        return 1;
    }else if (umap[0] == 2){
        return 1;
    }
    else return 0;
}
bool IsTwoPairs (int currentMax, int TwoPairsNum,unordered_map<int,int> umap){
    if(currentMax == 2 && TwoPairsNum == 2 && umap.find(0) == umap.end()){
        return 1;
    }else if(currentMax == 2 && TwoPairsNum == 1 && umap[0] >= 1){
        return 1;
    }
    else return 0;
}
bool IsPair     (int currentMax, int TwoPairsNum,unordered_map<int,int> umap){
    if(currentMax == 2 && TwoPairsNum == 1 && umap.find(0) == umap.end()){
        return 1;
    }else if(umap[0] >= 1){
        return 1;
    }
    else return 0;
}
```
### Result
![](https://i.imgur.com/CLLhD6g.png)
