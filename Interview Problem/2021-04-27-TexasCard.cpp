#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
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

class Card{
    public:
        int num;
        int suit;
};
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
        if(num == 14) Ocard.num = 1;
        else Ocard.num = num;
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
        if (it ->second > currentMax) {
            currentMax = it->second;
        }
        if (it ->second == 2) {
            TwoPairsNum+=1;
        }
    }
    cout << "Debug UMAP------------------" << endl;
    for (auto const &pair: umap) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
    cout << "Debug UMAP------------------" << endl;
    // Each function test
    if(IsRoyalFlush(VCard)){
        cout << "Input is Royal Flush" << endl;
        return RoyalFlush;
    }
    else if(IsStraightFlush(VCard)){
        cout << "Input is Straight Flush" << endl;
        return StraightFlush;
    }
    else if(IsFourKind(currentMax)) {
        cout << "Input is Four Kind" << endl;
        return FourKind;
    }
    else if(IsFullHouse(currentMax,TwoPairsNum)) {
        cout << "Input is Full House" << endl;
        return FullHouse;
    }
    else if(IsFlush(VCard)) {
        cout << "Input is Flush" << endl;
        return Flush;
    }
    else if(IsStraight(VCard)) {
        cout << "Input is Straight" << endl;
        return Straight;
    }
    else if(IsThreeKind(currentMax, TwoPairsNum)) {
        cout << "Input is Three Kind" << endl;
        return ThreeKind;
    }
    else if(IsTwoPairs(currentMax, TwoPairsNum)) {
        cout << "Input is Two Pairs" << endl;
        return TwoPairs;
    }
    else if(IsPair(currentMax, TwoPairsNum)) {
        cout << "Input is Pairs" << endl;
        return Pair;
    }
    else{
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
    // cout << AFlag << " " << KFlag << endl;
    if(KFlag == 1 && AFlag == 1){
        // cout << "Enter AKFlag" << endl;
        delta = 1; // K and A 's delta
        for(int i = 1; i < VCard.size() - 1; i++){
            delta += VCard[i+1].num - VCard[i].num;                                                                                                                              
        }
    }
    // cout << "Delta: " << delta << endl;
    if(delta == 4) return true;
    else return false;
}
bool IsFourKind(int currentMax){
    if(currentMax == 4) return 1;
    else return 0;
}
bool IsFullHouse(int currentMax, int TwoPairsNum){
    // cout << "currentMax: " << currentMax << " TwoPairsNum:" << TwoPairsNum << endl;
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