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
        cout << "Ocard.suit: " << Ocard.suit << endl;
        cout << "Ocard.num: " << Ocard.num << endl;
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
    cout << "Debug UMAP------------------" << endl;
    for (auto const &pair: umap) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
    cout << "Debug UMAP------------------" << endl;
    // Each function test
    if(IsRoyalFlush(VCard,umap)){
        cout << "Input is Royal Flush" << endl;
        return RoyalFlush;
    }
    else if(IsStraightFlush(VCard,umap)){
        cout << "Input is Straight Flush" << endl;
        return StraightFlush;
    }
    else if(IsFourKind(currentMax,umap)) {
        cout << "Input is Four Kind" << endl;
        return FourKind;
    }
    else if(IsFullHouse(currentMax,TwoPairsNum,umap)) {
        cout << "Input is Full House" << endl;
        return FullHouse;
    }
    else if(IsFlush(VCard,umap)) {
        cout << "Input is Flush" << endl;
        return Flush;
    }
    else if(IsStraight(VCard,umap)) {
        cout << "Input is Straight" << endl;
        return Straight;
    }
    else if(IsThreeKind(currentMax, TwoPairsNum,umap)) {
        cout << "Input is Three Kind" << endl;
        return ThreeKind;
    }
    else if(IsTwoPairs(currentMax, TwoPairsNum,umap)) {
        cout << "Input is Two Pairs" << endl;
        return TwoPairs;
    }
    else if(IsPair(currentMax, TwoPairsNum,umap)) {
        cout << "Input is Pairs" << endl;
        return Pair;
    }
    else{
        cout << "Input is Highcard" << endl;
        return Highcard;
    }
    
}
int main(){
    vector<int> input; // Straight 1,2,3,4,5
    input.push_back(0x205); // Club(22) 3
    input.push_back(0x202); // Club(22) 2
    input.push_back(0x203); // Club(22) 3
    input.push_back(0x304); // Heart(23) 4
    input.push_back(0x40e); // Heart(24) 1    
    cout << f(input) << endl;

    vector<int> input2; // Straight 10.J,Q,K,A
    input2.push_back(0x40e); // Spade(24) 1    
    input2.push_back(0x40d); // Spade(24) 13 K
    input2.push_back(0x20b); // Club(22) J
    input2.push_back(0x40c); // Spade(24) 12 Q
    input2.push_back(0x30a); // Heart(23) 10
    f(input2);

    vector<int> input3; // StraightFlush 2,3,4,5,6
    input3.push_back(0x402); // Spade(24) 2    
    input3.push_back(0x406); // Spade(24) 6
    input3.push_back(0x403); // Spade(24) 3
    input3.push_back(0x404); // Spade(24) 4
    input3.push_back(0x405); // Spade(24) 5
    f(input3);

    vector<int> input4; // RoyalFlush 10,J,Q,K,A
    input4.push_back(0x30b); // Hearts(23) J    
    input4.push_back(0x30c); // Hearts(23) Q
    input4.push_back(0x30d); // Hearts(23) K
    input4.push_back(0x30e); // Hearts(23) A
    input4.push_back(0x30a); // Hearts(23) 10
    f(input4);

    vector<int> input5; // Four Kind
    input5.push_back(0x105); // Diamonds(21) 	5    
    input5.push_back(0x305); // Hearts(23) 		5
    input5.push_back(0x205); // Clubs(22) 		5
    input5.push_back(0x405); // Spades(24) 		5
    input5.push_back(0x30a); // Hearts(23) 		10
    f(input5);

    vector<int> input6; // Full House
    input6.push_back(0x10d); // Diamonds(21) 	K    
    input6.push_back(0x30d); // Hearts(23) 		K
    input6.push_back(0x20d); // Clubs(22) 		K
    input6.push_back(0x403); // Spades(24) 		3
    input6.push_back(0x303); // Hearts(23) 		3
    f(input6);

    vector<int> input7; // Flush
    input7.push_back(0x40a); // Spades(24)		10
    input7.push_back(0x40d); // Spades(24)		K
    input7.push_back(0x40b); // Spades(24)		J
    input7.push_back(0x403); // Spades(24) 		3
    input7.push_back(0x407); // Spades(24) 		7
    f(input7);

    vector<int> input8; // Three Kind
    input8.push_back(0x40a); // Spades(24)		10
    input8.push_back(0x30a); // Hearts(23)		10
    input8.push_back(0x20a); // Clubs(22)		10
    input8.push_back(0x403); // Spades(24) 		3
    input8.push_back(0x407); // Spades(24) 		7
    f(input8);

    vector<int> input9; // Two Pairs
    input9.push_back(0x40a); // Spades(24)		10
    input9.push_back(0x30a); // Hearts(23)		10
    input9.push_back(0x203); // Clubs(22)		3
    input9.push_back(0x403); // Spades(24) 		3
    input9.push_back(0x407); // Spades(24) 		7
    f(input9);

    vector<int> input10; // Pair
    input10.push_back(0x40a); // Spades(24)		10
    input10.push_back(0x30a); // Hearts(23)		10
    input10.push_back(0x204); // Clubs(22)		4
    input10.push_back(0x403); // Spades(24) 		3
    input10.push_back(0x407); // Spades(24) 		7
    f(input10);

    vector<int> input11; // High Card
    input11.push_back(0x409); // Spades(24)		9
    input11.push_back(0x30a); // Hearts(23)		10
    input11.push_back(0x204); // Clubs(22)		4
    input11.push_back(0x403); // Spades(24) 	3
    input11.push_back(0x407); // Spades(24) 	7
    cout << f(input11) << endl;

    vector<int> input12; // Straight 10.J,Q,K,A
    input12.push_back(0x40e); // Spade(24) 1    
    input12.push_back(0x40d); // Spade(24) 13 K
    input12.push_back(0x20b); // Club(22) J
    input12.push_back(0x610); // Joker
    input12.push_back(0x50f); // Joker
    cout << f(input12) << endl;

    vector<int> input13; // StraightFlush 2,3,4,5,6
    input13.push_back(0x610); // Joker
    input13.push_back(0x50f); // Joker
    input13.push_back(0x403); // Spade(24) 3
    input13.push_back(0x404); // Spade(24) 4
    input13.push_back(0x405); // Spade(24) 5
    f(input13);

    vector<int> input14; // RoyalFlush 10,J,Q,K,A
    // input14.push_back(0x30b); // Hearts(23) J   
    input14.push_back(0x610); // Hearts(23) J    two Joker
    input14.push_back(0x50f); // Joker
    input14.push_back(0x30d); // Hearts(23) K
    input14.push_back(0x30e); // Hearts(23) A
    input14.push_back(0x30a); // Hearts(23) 10
    f(input14);

    vector<int> input15; // Four Kind
    input15.push_back(0x610); // Diamonds(21) 	5    
    // input15.push_back(0x305); // Hearts(23) 	5
    input15.push_back(0x50f); // Hearts(23) 	5
    input15.push_back(0x204); // Clubs(22) 		5
    input15.push_back(0x404); // Spades(24) 	5
    input15.push_back(0x30a); // Hearts(23) 	10
    f(input15);

    vector<int> input16; // Full House
    input16.push_back(0x610); // Diamonds(21) 		K    
    // input16.push_back(0x30d); // Hearts(23) 		K
    input16.push_back(0x50f); // Hearts(23) 	5
    input16.push_back(0x20d); // Clubs(22) 			K
    input16.push_back(0x403); // Spades(24) 		3
    input16.push_back(0x304); // Hearts(23) 		4
    f(input16);

    vector<int> input17; // Flush
    input17.push_back(0x50f); // Spades(24)		10
    input17.push_back(0x40d); // Spades(24)		K
    input17.push_back(0x610); // Spades(24)		J
    input17.push_back(0x403); // Spades(24) 		3
    input17.push_back(0x407); // Spades(24) 		7
    f(input17);
    
    // int t1 = 0x102;
    // for(int i = 0; i < 13; i++){
    //     cout << i << ": " << (t1 + i) / 0x100 << endl;
    // }
    // cout << "-----------------" << endl;
    // int t2 = 0x202;
    // for(int i = 0; i < 13; i++){
    //     cout << i << ": " << (t2 + i) / 0x100 << endl;
    // }
    // cout << "-----------------" << endl;
    // int t3 = 0x302;
    // for(int i = 0; i < 13; i++){
    //     cout << i << ": " << (t3 + i) / 0x100 << endl;
    // }
    // cout << "-----------------" << endl;
    // int t4 = 0x402;
    // for(int i = 0; i < 13; i++){
    //     cout << i << ": " << (t4 + i) / 0x100 << endl;
    // }

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
    // for(int i = 0; i < VCardNum.size(); i++){
    //     cout << VCardNum[i] << endl;
    // }
    std::vector<int> result;
    std::set_difference(checkData.begin(),checkData.end(), VCardNum.begin(), VCardNum.end(),
        std::inserter(result, result.end()));
    // std::transform(checkData.begin(),checkData.end(), VCardNum.begin(), VCardNum.end(), std::minus<int>());
    // checkData -= VCardNum;
    // cout << "Result ++++=" << endl;
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
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
            // cout << "Enter cmpSuit != Joker" << endl;
            cmpSuit = VCard[i].suit;
            break;
        }
    }
    if(IsStraight(VCard,umap)){
        for(int i = 0; i < VCard.size(); i++){
            cout << "VCard[i].suit: " << VCard[i].suit << endl;
            if((cmpSuit != VCard[i].suit) && (VCard[i].suit != Joker)){
                // cout << "Enter compare" << endl;
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
        cout << "Enter AKFlag" << endl;
        delta = 1; // K and A 's delta
        for(int i = 1; i < VCard.size() - 1; i++){
            if(VCard[i+1].num != 0 && VCard[i].num != 0
                && VCard[i].num != 1 && VCard[i+1].num != 1){
                    cout << "VCard[i+1].num: " << VCard[i+1].num << " VCard[i].num; " << VCard[i].num << endl;
                    delta += VCard[i+1].num - VCard[i].num;   
            }                                                                                                                            
        }
    }
    else {
        for(int i = 0; i < VCard.size() - 1; i++){
            if(VCard[i+1].num != 0 && VCard[i].num != 0){
                cout << "VCard[i+1].num: " << VCard[i+1].num << " VCard[i].num; " << VCard[i].num << endl;
                delta += VCard[i+1].num - VCard[i].num;   
            }                                                                                                                                  
        }
    }
    cout << "Delta: " << delta << endl;
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
    // cout << "currentMax: " << currentMax << " TwoPairsNum:" << TwoPairsNum << endl;
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