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
bool IsFourKind(vector<Card>,int);
bool IsFullHouse(vector<Card>);
bool IsFlush    (vector<Card>);
bool IsStraight (vector<Card>);
bool IsThreeKind(vector<Card>);
bool IsTwoPairs (vector<Card>);
bool IsPair     (vector<Card>);
bool IsHighcard (vector<Card>);

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
    for(auto it = umap.cbegin(); it != umap.cend(); ++it){
        if (it ->second > currentMax) {
            currentMax = it->second;
        }
    }
    cout << "Debug UMAP------------------" << endl;
    for (auto const &pair: umap) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
    cout << "Debug UMAP------------------" << endl;
    // Each function test
    if(IsRoyalFlush(VCard)) cout << "Input is Royal Flush" << endl;
    if(IsStraightFlush(VCard)) cout << "Input is Straight Flush" << endl;
    if(IsFourKind(VCard,currentMax)) cout << "Input is Four Kind Flush" << endl;
    if(IsStraight(VCard)) cout << "Input is Straight" << endl;


    for(int i = 0; i < VCard.size(); i++){
        cout << VCard[i].num << endl;
    }
    return 1;
    
}
int main(){
    vector<int> input; // Straight 1,2,3,4,5
    input.push_back(0x205); // Club(22) 3
    input.push_back(0x202); // Club(22) 2
    input.push_back(0x203); // Club(22) 3
    input.push_back(0x304); // Heart(23) 4
    input.push_back(0x40e); // Heart(24) 1    
    f(input);

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
bool IsFourKind(vector<Card> VCard,int currentMax){
    if(currentMax == 4) return 1;
    else return 0;
}
bool IsFullHouse(vector<Card>);
bool IsFlush    (vector<Card>);
bool IsStraight (vector<Card>);
bool IsThreeKind(vector<Card>);
bool IsTwoPairs (vector<Card>);
bool IsPair     (vector<Card>);
bool IsHighcard (vector<Card>);