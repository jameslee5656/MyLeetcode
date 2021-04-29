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