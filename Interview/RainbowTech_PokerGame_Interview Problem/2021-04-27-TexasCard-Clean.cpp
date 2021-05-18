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