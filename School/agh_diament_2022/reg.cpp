// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

vector<int> gotowe = {0, 1, 2, 3, 3, 4, 5, 6, 5, 4, 5, 6}; // size = 11
int n, ans;

bool is_sorted(int x){
  string s = to_string(x);

  for(int i = 0; i < s.size()-1; i++)
    if(s[i] < s[i+1])
      return false;

  return true;
} 

void calc_comb(string str, int i, int len, vector<string> &comb){
  if(i == len - 1 && str[0] != '0'){
    comb.push_back(str);
    return;
  }

  for(int j = i; j < len; j++){
    swap(str[i], str[j]);
    calc_comb(str, i + 1, len, comb);
    swap(str[i], str[j]);
  }
}

// op - operation 0-sort, 1-pierwiastek
void foo(int x, bool op, int res){
  if(x <= 11){
    cout << "\n";
    res += gotowe[x];
    ans = min(ans, res);
    return;
  }

  if(op == 0){
    if(!is_sorted(x)) 
      foo(x, 1, res);

    string str = to_string(x);
    vector<string> comb;
    calc_comb(str, 0, str.size(), comb);
    for(string &s : comb){
      int int_perm = stoi(s);
      if(int_perm == x)
        foo(stoi(s), 1, res);
      else
        foo(stoi(s), 1, res+1);
    }
  }
  else{
    float _pierw = sqrt(x);
    if(_pierw-floor(_pierw) >= 0.5)
      _pierw = ceil(_pierw);
    else
      _pierw = floor(_pierw);
    
    int pierw = (int)_pierw;
    int diff = abs(x - pierw*pierw);

    foo(pierw, 0, res+diff+1);
  }
  cout << x << " <- ";
}

int solve(int x){
  ans = 200001;
  if(is_sorted(x)){
    foo(n, 0, 0);
  }
  else{
    foo(n, 1, 0);
  }

  return ans;
}

int main(){
  //fastio;
  cin >> n;
  int res = solve(n);
  cout << "\n" << res;
}

void test(){
  vector<pair<int, string>> brut{
      {1, "i"},
      {2, "ii"},
      {3, "iii"},
      {4, "iis"},
      {9, "iiis"},
      {5, "iisi"},
      {16, "iiss"},
      {10, "iiisi"},
      {6, "iisii"},
      {8, "iiisd"},
      {81, "iiiss"},
      {25, "iisis"},
      {17, "iissi"},
      {15, "iissd"},
      {256, "iisss"},
      {61, "iissp"},
      {11, "iiisii"},
      {7, "iisiii"},
      {100, "iiisis"},
      {82, "iiissi"},
      {36, "iisiis"},
      {26, "iisisi"},
      {18, "iissii"},
      {64, "iiisds"},
      {80, "iiissd"},
      {24, "iisisd"},
      {6561, "iiisss"},
      {625, "iisiss"},
      {289, "iissis"},
      {257, "iisssi"},
      {52, "iisisp"},
      {71, "iissip"},
      {62, "iisspi"},
      {14, "iissdd"},
      {225, "iissds"},
      {255, "iisssd"},
      {51, "iissdp"},
      {60, "iisspd"},
      {65536, "iissss"},
      {652, "iisssp"},
      {3721, "iissps"},
      {12, "iiisiii"},
      {121, "iiisiis"},
      {101, "iiisisi"},
      {83, "iiissii"},
      {49, "iisiiis"},
      {37, "iisiisi"},
      {27, "iisisii"},
      {19, "iissiii"},
      {99, "iiisisd"},
      {65, "iiisdsi"},
      {35, "iisiisd"},
      {10000, "iiisiss"},
      {6724, "iiissis"},
      {6562, "iiisssi"},
      {1296, "iisiiss"},
      {676, "iisisis"},
      {626, "iisissi"},
      {324, "iissiis"},
      {290, "iissisi"},
      {258, "iisssii"},
      {63, "iisiisp"},
      {53, "iisispi"},
      {72, "iissipi"},
      {79, "iiissdd"},
      {23, "iisisdd"},
      {4096, "iiisdss"},
      {6400, "iiissds"},
      {6560, "iiisssd"},
      {576, "iisisds"},
      {624, "iisissd"},
      {288, "iissisd"},
      {226, "iissdsi"},
      {42, "iisisdp"},
      {70, "iissipd"},
      {83521, "iississ"},
      {66049, "iisssis"},
      {65537, "iissssi"},
      {6651, "iiisssp"},
      {2704, "iisisps"},
      {982, "iissisp"},
      {5041, "iissips"},
      {752, "iisssip"},
      {653, "iissspi"},
      {3844, "iisspis"},
      {3722, "iisspsi"},
      {13, "iissddd"},
      {196, "iissdds"},
      {224, "iissdsd"},
      {254, "iisssdd"},
      {41, "iissddp"},
      {50, "iissdpd"},
      {59, "iisspdd"},
      {50625, "iissdss"},
      {65025, "iisssds"},
      {65535, "iissssd"},
      {522, "iissdsp"},
      {2601, "iissdps"},
      {552, "iisssdp"},
      {651, "iissspd"},
      {3600, "iisspds"},
      {3720, "iisspsd"},
      {66553, "iissssp"},
      {7321, "iisspsp"},
      {144, "iiisiiis"},
      {122, "iiisiisi"},
      {102, "iiisisii"},
      {84, "iiissiii"},
      {38, "iisiisii"},
      {28, "iisisiii"},
      {20, "iissiiii"},
      {21, "iiisiiip"},
      {120, "iiisiisd"},
      {66, "iiisdsii"},
      {48, "iisiiisd"},
      {14641, "iiisiiss"},
      {10201, "iiisisis"},
      {10001, "iiisissi"},
      {6889, "iiissiis"},
      {6725, "iiissisi"},
      {6563, "iiisssii"},
      {2401, "iisiiiss"},
      {1369, "iisiisis"},
      {1297, "iisiissi"},
      {729, "iisisiis"},
      {677, "iisisisi"},
      {627, "iisissii"},
      {361, "iissiiis"},
      {325, "iissiisi"},
      {291, "iissisii"},
      {259, "iisssiii"},
      {211, "iiisiisp"},
      {110, "iiisisip"},
      {94, "iisiiisp"},
      {73, "iisiisip"},
      {54, "iisispii"},
      {91, "iissiiip"},
      {98, "iiisisdd"},
      {34, "iisiisdd"},
      {9801, "iiisisds"},
      {9999, "iiisissd"},
      {4225, "iiisdsis"},
      {4097, "iiisdssi"},
      {6723, "iiissisd"},
      {6401, "iiissdsi"},
      {1225, "iisiisds"},
      {1295, "iisiissd"},
      {675, "iisisisd"},
      {577, "iisisdsi"},
      {323, "iissiisd"},
      {227, "iissdsii"},
      {43, "iisisdpi"},
      {104976, "iissiiss"},
      {84100, "iissisis"},
      {83522, "iississi"},
      {66564, "iisssiis"},
      {66050, "iisssisi"},
      {65538, "iissssii"},
      {7642, "iiissisp"},
      {6652, "iiisssip"},
      {9621, "iisiissp"},
      {3969, "iisiisps"},
      {766, "iisisisp"},
      {662, "iisissip"},
      {2809, "iisispis"},
      {2705, "iisispsi"},
      {432, "iissiisp"},
      {920, "iissisip"},
      {983, "iissispi"},
      {5184, "iissipis"},
      {5042, "iissipsi"},
      {852, "iisssiip"},
      {753, "iisssipi"},
      {654, "iissspii"},
      {3845, "iisspisi"},
      {3723, "iisspsii"},
      {78, "iiissddd"},
      {22, "iisisddd"},
      {4095, "iiisdssd"},
      {6241, "iiissdds"},
      {6399, "iiissdsd"},
      {6559, "iiisssdd"},
      {529, "iisisdds"},
      {575, "iisisdsd"},
      {623, "iisissdd"},
      {287, "iissisdd"},
      {197, "iissddsi"},
      {97, "iiissddp"},
      {32, "iisisddp"},
      {69, "iissipdd"},
      {82944, "iissisds"},
      {83520, "iississd"},
      {51076, "iissdsis"},
      {50626, "iissdssi"},
      {66048, "iisssisd"},
      {65026, "iisssdsi"},
      {9640, "iiisdssp"},
      {6650, "iiisssdp"},
      {765, "iisisdsp"},
      {1764, "iisisdps"},
      {642, "iisissdp"},
      {2703, "iisispsd"},
      {882, "iissisdp"},
      {981, "iissispd"},
      {4900, "iissipds"},
      {5040, "iissipsd"},
      {622, "iissdsip"},
      {523, "iissdspi"},
      {2602, "iissdpsi"},
      {751, "iisssipd"},
      {553, "iisssdpi"},
      {3843, "iisspisd"},
      {3601, "iisspdsi"},
      {85321, "iississp"},
      {96640, "iisssisp"},
      {76553, "iissssip"},
      {66554, "iisssspi"},
      {7420, "iisispsp"},
      {5410, "iissipsp"},
      {8443, "iisspisp"},
      {7322, "iisspsip"},
      {169, "iissddds"},
      {195, "iissddsd"},
      {223, "iissdsdd"},
      {253, "iisssddd"},
      {31, "iissdddp"},
      {40, "iissddpd"},
      {58, "iisspddd"},
      {38416, "iissddss"},
      {50176, "iissdsds"},
      {50624, "iissdssd"},
      {64516, "iisssdds"},
      {65024, "iisssdsd"},
      {65534, "iissssdd"},
      {961, "iissddsp"},
      {1681, "iissddps"},
      {422, "iissdsdp"},
      {521, "iissdspd"},
      {2500, "iissdpds"},
      {2600, "iissdpsd"},
      {542, "iisssddp"},
      {551, "iisssdpd"},
      {650, "iissspdd"},
      {3481, "iisspdds"},
      {3599, "iisspdsd"},
      {3719, "iisspsdd"},
      {95, "iisspddp"},
      {65520, "iissdssp"},
      {65553, "iissssdp"},
      {66552, "iisssspd"},
      {6210, "iissdpsp"},
      {6300, "iisspdsp"},
      {7320, "iisspsdp"},
      {145, "iiisiiisi"},
      {123, "iiisiisii"},
      {103, "iiisisiii"},
      {85, "iiissiiii"},
      {39, "iisiisiii"},
      {29, "iisisiiii"},
      {143, "iiisiiisd"},
      {67, "iiisdsiii"},
      {20736, "iiisiiiss"},
      {14884, "iiisiisis"},
      {14642, "iiisiissi"},
      {10404, "iiisisiis"},
      {10202, "iiisisisi"},
      {10002, "iiisissii"},
      {7056, "iiissiiis"},
      {6890, "iiissiisi"},
      {6726, "iiissisii"},
      {6564, "iiisssiii"},
      {2402, "iisiiissi"},
      {1444, "iisiisiis"},
      {1370, "iisiisisi"},
      {1298, "iisiissii"},
      {784, "iisisiiis"},
      {730, "iisisiisi"},
      {678, "iisisisii"},
      {628, "iisissiii"},
      {400, "iissiiiis"},
      {362, "iissiiisi"},
      {326, "iissiisii"},
      {292, "iissisiii"},
      {260, "iisssiiii"},
      {441, "iiisiiisp"},
      {221, "iiisiisip"},
      {212, "iiisiispi"},
      {210, "iiisisiip"},
      {111, "iiisisipi"},
      {74, "iisiisipi"},
      {55, "iisispiii"},
      {92, "iissiiipi"},
      {119, "iiisiisdd"},
      {47, "iisiiisdd"},
      {14400, "iiisiisds"},
      {14640, "iiisiissd"},
      {10200, "iiisisisd"},
      {9802, "iiisisdsi"},
      {4356, "iiisdsiis"},
      {4226, "iiisdsisi"},
      {4098, "iiisdssii"},
      {6888, "iiissiisd"},
      {6402, "iiissdsii"},
      {2304, "iisiiisds"},
      {2400, "iisiiissd"},
      {1368, "iisiisisd"},
      {1226, "iisiisdsi"},
      {728, "iisisiisd"},
      {578, "iisisdsii"},
      {360, "iissiiisd"},
      {228, "iissdsiii"},
      {109, "iiisisipd"},
      {93, "iisiiispd"},
      {44, "iisisdpii"},
      {90, "iissiiipd"},
      {130321, "iissiiiss"},
      {105625, "iissiisis"},
      {104977, "iissiissi"},
      {84681, "iissisiis"},
      {84101, "iissisisi"},
      {83523, "iississii"},
      {67081, "iisssiiis"},
      {66565, "iisssiisi"},
      {66051, "iisssisii"},
      {65539, "iissssiii"},
      {64411, "iiisiissp"},
      {44521, "iiisiisps"},
      {21100, "iiisisisp"},
      {12100, "iiisisips"},
      {11000, "iiisissip"},
      {9886, "iiissiisp"},
      {7652, "iiissisip"},
      {7643, "iiissispi"},
      {6653, "iiisssiip"},
      {4210, "iisiiissp"},
      {8836, "iisiiisps"},
      {9631, "iisiisisp"},
      {5329, "iisiisips"},
      {9721, "iisiissip"},
      {9622, "iisiisspi"},
      {3970, "iisiispsi"},
      {972, "iisisiisp"},
      {776, "iisisisip"},
      {767, "iisisispi"},
      {762, "iisissiip"},
      {663, "iisissipi"},
      {2916, "iisispiis"},
      {2810, "iisispisi"},
      {2706, "iisispsii"},
      {631, "iissiiisp"},
      {8281, "iissiiips"},
      {532, "iissiisip"},
      {433, "iissiispi"},
      {921, "iissisiip"},
      {984, "iissispii"},
      {5185, "iissipisi"},
      {5043, "iissipsii"},
      {952, "iisssiiip"},
      {853, "iisssiipi"},
      {754, "iisssipii"},
      {655, "iissspiii"},
      {3846, "iisspisii"},
      {3724, "iisspsiii"},
      {33, "iisiisddd"},
      {9604, "iiisisdds"},
      {9800, "iiisisdsd"},
      {9998, "iiisissdd"},
      {4224, "iiisdsisd"},
      {6722, "iiissisdd"},
      {6242, "iiissddsi"},
      {1156, "iisiisdds"},
      {1224, "iisiisdsd"},
      {1294, "iisiissdd"},
      {674, "iisisisdd"},
      {530, "iisisddsi"},
      {322, "iissiisdd"},
      {198, "iissddsii"},
      {104329, "iissiisds"},
      {104975, "iissiissd"},
      {84099, "iissisisd"},
      {82945, "iissisdsi"},
      {51529, "iissdsiis"},
      {51077, "iissdsisi"},
      {50627, "iissdssii"},
      {66563, "iisssiisd"},
      {65027, "iisssdsii"},
      {9810, "iiisisdsp"},
      {5422, "iiisdsisp"},
      {9740, "iiisdssip"},
      {9641, "iiisdsspi"},
      {7632, "iiissisdp"},
      {7641, "iiissispd"},
      {6410, "iiissdsip"},
      {5221, "iisiisdsp"},
      {9521, "iisiissdp"},
      {9620, "iisiisspd"},
      {3968, "iisiispsd"},
      {775, "iisisdsip"},
      {1849, "iisisdpis"},
      {1765, "iisisdpsi"},
      {661, "iisissipd"},
      {643, "iisissdpi"},
      {2808, "iisispisd"},
      {332, "iissiisdp"},
      {431, "iissiispd"},
      {919, "iissisipd"},
      {883, "iissisdpi"},
      {5183, "iissipisd"},
      {4901, "iissipdsi"},
      {722, "iissdsiip"},
      {524, "iissdspii"},
      {2603, "iissdpsii"},
      {851, "iisssiipd"},
      {554, "iisssdpii"},
      {3602, "iisspdsii"},
      {186624, "iissiisps"},
      {85322, "iississip"},
      {66654, "iisssiisp"},
      {66500, "iisssisip"},
      {96641, "iisssispi"},
      {86553, "iissssiip"},
      {76554, "iissssipi"},
      {66555, "iisssspii"},
      {9963, "iisiispsp"},
      {9820, "iisispisp"},
      {7520, "iisispsip"},
      {7421, "iisispspi"},
      {8541, "iissipisp"},
      {5420, "iissipsip"},
      {5411, "iissipspi"},
      {8543, "iisspisip"},
      {8444, "iisspispi"},
      {7332, "iisspsiip"},
      {7323, "iisspsipi"},
      {77, "iiissdddd"},
      {4094, "iiisdssdd"},
      {6084, "iiissddds"},
      {6240, "iiissddsd"},
      {6398, "iiissdsdd"},
      {6558, "iiisssddd"},
      {484, "iisisddds"},
      {528, "iisisddsd"},
      {574, "iisisdsdd"},
      {286, "iissisddd"},
      {170, "iissdddsi"},
      {87, "iiissdddp"},
      {96, "iiissddpd"},
      {68, "iissipddd"},
      {82369, "iissisdds"},
      {82943, "iissisdsd"},
      {83519, "iississdd"},
      {38809, "iissddsis"},
      {38417, "iissddssi"},
      {51075, "iissdsisd"},
      {50177, "iissdsdsi"},
      {66047, "iisssisdd"},
      {64517, "iisssddsi"},
      {9540, "iiisdssdp"},
      {9639, "iiisdsspd"},
      {6421, "iiissddsp"},
      {9409, "iiissddps"},
      {9655, "iiisssddp"},
      {6649, "iiisssdpd"},
      {1024, "iisisddps"},
      {755, "iisisdsdp"},
      {764, "iisisdspd"},
      {1763, "iisisdpsd"},
      {632, "iisissddp"},
      {641, "iisissdpd"},
      {2702, "iisispsdd"},
      {872, "iissisddp"},
      {881, "iissisdpd"},
      {980, "iissispdd"},
      {4761, "iissipdds"},
      {4899, "iissipdsd"},
      {5039, "iissipsdd"},
      {971, "iissddsip"},
      {962, "iissddspi"},
      {1682, "iissddpsi"},
      {621, "iissdsipd"},
      {423, "iissdsdpi"},
      {2501, "iissdpdsi"},
      {750, "iisssipdd"},
      {543, "iisssddpi"},
      {3842, "iisspisdd"},
      {3482, "iisspddsi"},
      {98442, "iissisdsp"},
      {85320, "iississdp"},
      {76510, "iissdsisp"},
      {66520, "iissdssip"},
      {65521, "iissdsspi"},
      {86640, "iisssisdp"},
      {96639, "iisssispd"},
      {76552, "iissssipd"},
      {65554, "iissssdpi"},
      {7419, "iisispspd"},
      {9400, "iissipdsp"},
      {5400, "iissipsdp"},
      {5409, "iissipspd"},
      {6220, "iissdpsip"},
      {6211, "iissdpspi"},
      {8433, "iisspisdp"},
      {8442, "iisspispd"},
      {6310, "iisspdsip"},
      {6301, "iisspdspi"},
      {168, "iissdddsd"},
      {194, "iissddsdd"},
      {222, "iissdsddd"},
      {252, "iisssdddd"},
      {30, "iissdddpd"},
      {57, "iisspdddd"},
      {28561, "iissdddss"},
      {38025, "iissddsds"},
      {38415, "iissddssd"},
      {49729, "iissdsdds"},
      {50175, "iissdsdsd"},
      {50623, "iissdssdd"},
      {64009, "iisssddds"},
      {64515, "iisssddsd"},
      {65023, "iisssdsdd"},
      {65533, "iissssddd"},
      {951, "iissddsdp"},
      {960, "iissddspd"},
      {1600, "iissddpds"},
      {1680, "iissddpsd"},
      {421, "iissdsdpd"},
      {520, "iissdspdd"},
      {2499, "iissdpdsd"},
      {2599, "iissdpsdd"},
      {541, "iisssddpd"},
      {550, "iisssdpdd"},
      {649, "iissspddd"},
      {3364, "iisspddds"},
      {3480, "iisspddsd"},
      {3598, "iisspdsdd"},
      {3718, "iisspsddd"},
      {86431, "iissddssp"},
      {178084, "iissdsdps"},
      {65420, "iissdssdp"},
      {65519, "iissdsspd"},
      {66541, "iisssddsp"},
      {65543, "iissssddp"},
      {65552, "iissssdpd"},
      {66551, "iisssspdd"},
      {8611, "iissddpsp"},
      {5200, "iissdpdsp"},
      {6200, "iissdpsdp"},
      {6209, "iissdpspd"},
      {8431, "iisspddsp"},
      {9025, "iisspddps"},
      {9953, "iisspdsdp"},
      {6299, "iisspdspd"},
      {9731, "iisspsddp"},
      {7319, "iisspsdpd"},
      {146, "iiisiiisii"},
      {124, "iiisiisiii"},
      {104, "iiisisiiii"},
      {86, "iiissiiiii"},
      {21025, "iiisiiisis"},
      {20737, "iiisiiissi"},
      {15129, "iiisiisiis"},
      {14885, "iiisiisisi"},
      {14643, "iiisiissii"},
      {10609, "iiisisiiis"},
      {10405, "iiisisiisi"},
      {10203, "iiisisisii"},
      {10003, "iiisissiii"},
      {7225, "iiissiiiis"},
      {7057, "iiissiiisi"},
      {6891, "iiissiisii"},
      {6727, "iiissisiii"},
      {6565, "iiisssiiii"},
      {2403, "iisiiissii"},
      {1521, "iisiisiiis"},
      {1445, "iisiisiisi"},
      {1371, "iisiisisii"},
      {1299, "iisiissiii"},
      {841, "iisisiiiis"},
      {785, "iisisiiisi"},
      {731, "iisisiisii"},
      {679, "iisisisiii"},
      {629, "iisissiiii"},
      {401, "iissiiiisi"},
      {363, "iissiiisii"},
      {327, "iissiisiii"},
      {293, "iissisiiii"},
      {261, "iisssiiiii"},
      {442, "iiisiiispi"},
      {321, "iiisiisiip"},
      {213, "iiisiispii"},
      {310, "iiisisiiip"},
      {112, "iiisisipii"},
      {75, "iisiisipii"},
      {56, "iisispiiii"},
      {142, "iiisiiisdd"},
      {20449, "iiisiiisds"},
      {20735, "iiisiiissd"},
      {14883, "iiisiisisd"},
      {14401, "iiisiisdsi"},
      {10403, "iiisisiisd"},
      {9803, "iiisisdsii"},
      {4489, "iiisdsiiis"},
      {4357, "iiisdsiisi"},
      {4227, "iiisdsisii"},
      {4099, "iiisdssiii"},
      {7055, "iiissiiisd"},
      {6403, "iiissdsiii"},
      {2305, "iisiiisdsi"},
      {1443, "iisiisiisd"},
      {1227, "iisiisdsii"},
      {783, "iisisiiisd"},
      {579, "iisisdsiii"},
      {399, "iissiiiisd"},
      {229, "iissdsiiii"},
      {440, "iiisiiispd"},
      {220, "iiisiisipd"},
      {209, "iiisisiipd"},
      {76, "iiisdsiiip"},
      {45, "iisisdpiii"},
      {160000, "iissiiiiss"},
      {131044, "iissiiisis"},
      {130322, "iissiiissi"},
      {106276, "iissiisiis"},
      {105626, "iissiisisi"},
      {104978, "iissiissii"},
      {85264, "iissisiiis"},
      {84682, "iissisiisi"},
      {84102, "iissisisii"},
      {83524, "iississiii"},
      {67600, "iisssiiiis"},
      {67082, "iisssiiisi"},
      {66566, "iisssiisii"},
      {66052, "iisssisiii"},
      {65540, "iissssiiii"},
      {76320, "iiisiiissp"},
      {194481, "iiisiiisps"},
      {88441, "iiisiisisp"},
      {48841, "iiisiisips"},
      {64421, "iiisiissip"},
      {64412, "iiisiisspi"},
      {44944, "iiisiispis"},
      {44522, "iiisiispsi"},
      {44100, "iiisisiisp"},
      {22100, "iiisisisip"},
      {21101, "iiisisispi"},
      {12321, "iiisisipis"},
      {12101, "iiisisipsi"},
      {21000, "iiisissiip"},
      {11001, "iiisissipi"},
      {7650, "iiissiiisp"},
      {9860, "iiissiisip"},
      {9887, "iiissiispi"},
      {7662, "iiissisiip"},
      {7653, "iiissisipi"},
      {7644, "iiissispii"},
      {6654, "iiisssiiip"},
      {4220, "iisiiissip"},
      {4211, "iisiiisspi"},
      {8837, "iisiiispsi"},
      {4441, "iisiisiisp"},
      {7310, "iisiisisip"},
      {9632, "iisiisispi"},
      {5476, "iisiisipis"},
      {5330, "iisiisipsi"},
      {9821, "iisiissiip"},
      {9722, "iisiissipi"},
      {9623, "iisiisspii"},
      {3971, "iisiispsii"},
      {874, "iisisiiisp"},
      {973, "iisisiispi"},
      {876, "iisisisiip"},
      {777, "iisisisipi"},
      {768, "iisisispii"},
      {862, "iisissiiip"},
      {763, "iisissiipi"},
      {664, "iisissipii"},
      {3025, "iisispiiis"},
      {2917, "iisispiisi"},
      {2811, "iisispisii"},
      {2707, "iisispsiii"},
      {8464, "iissiiipis"},
      {8282, "iissiiipsi"},
      {533, "iissiisipi"},
      {434, "iissiispii"},
      {922, "iissisiiip"},
      {985, "iissispiii"},
      {5186, "iissipisii"},
      {5044, "iissipsiii"},
      {620, "iisssiiiip"},
      {953, "iisssiiipi"},
      {854, "iisssiipii"},
      {656, "iissspiiii"},
      {3847, "iisspisiii"},
      {3725, "iisspsiiii"},
      {118, "iiisiisddd"},
      {46, "iisiiisddd"},
      {14161, "iiisiisdds"},
      {14399, "iiisiisdsd"},
      {14639, "iiisiissdd"},
      {10199, "iiisisisdd"},
      {9605, "iiisisddsi"},
      {4355, "iiisdsiisd"},
      {6887, "iiissiisdd"},
      {6243, "iiissddsii"},
      {2209, "iisiiisdds"},
      {2303, "iisiiisdsd"},
      {2399, "iisiiissdd"},
      {1367, "iisiisisdd"},
      {1157, "iisiisddsi"},
      {727, "iisisiisdd"},
      {531, "iisisddsii"},
      {359, "iissiiisdd"},
      {199, "iissddsiii"},
      {911, "iiisiisddp"},
      {108, "iiisisipdd"},
      {89, "iissiiipdd"},
      {129600, "iissiiisds"},
      {130320, "iissiiissd"},
      {105624, "iissiisisd"},
      {104330, "iissiisdsi"},
      {84680, "iissisiisd"},
      {82946, "iissisdsii"},
      {51984, "iissdsiiis"},
      {51530, "iissdsiisi"},
      {51078, "iissdsisii"},
      {50628, "iissdssiii"},
      {67080, "iisssiiisd"},
      {65028, "iisssdsiii"},
      {64410, "iiisiissdp"},
      {44520, "iiisiispsd"},
      {21099, "iiisisispd"},
      {11881, "iiisisipds"},
      {12099, "iiisisipsd"},
      {9811, "iiisisdspi"},
      {10999, "iiisissipd"},
      {6543, "iiisdsiisp"},
      {6422, "iiisdsisip"},
      {5423, "iiisdsispi"},
      {9840, "iiisdssiip"},
      {9741, "iiisdssipi"},
      {9642, "iiisdsspii"},
      {8886, "iiissiisdp"},
      {9885, "iiissiispd"},
      {7651, "iiissisipd"},
      {7633, "iiissisdpi"},
      {6420, "iiissdsiip"},
      {6411, "iiissdsipi"},
      {4320, "iisiiisdsp"},
      {4200, "iisiiissdp"},
      {4209, "iisiiisspd"},
      {8649, "iisiiispds"},
      {8835, "iisiiispsd"},
      {8631, "iisiisisdp"},
      {9630, "iisiisispd"},
      {5328, "iisiisipsd"},
      {6221, "iisiisdsip"},
      {5222, "iisiisdspi"},
      {9720, "iisiissipd"},
      {9522, "iisiissdpi"},
      {875, "iisisdsiip"},
      {1936, "iisisdpiis"},
      {1850, "iisisdpisi"},
      {1766, "iisisdpsii"},
      {761, "iisissiipd"},
      {644, "iisissdpii"},
      {2915, "iisispiisd"},
      {630, "iissiiisdp"},
      {8100, "iissiiipds"},
      {8280, "iissiiipsd"},
      {333, "iissiisdpi"},
      {884, "iissisdpii"},
      {4902, "iissipdsii"},
      {822, "iissdsiiip"},
      {723, "iissdsiipi"},
      {525, "iissdspiii"},
      {2604, "iissdpsiii"},
      {555, "iisssdpiii"},
      {3603, "iisspdsiii"},
      {910, "iiisisipdp"},
      {187489, "iissiispis"},
      {186625, "iissiispsi"},
      {88641, "iissisiisp"},
      {84110, "iissisisip"},
      {85332, "iississiip"},
      {85323, "iississipi"},
      {87610, "iisssiiisp"},
      {66655, "iisssiisip"},
      {66510, "iisssisiip"},
      {66501, "iisssisipi"},
      {96642, "iisssispii"},
      {96553, "iissssiiip"},
      {86554, "iissssiipi"},
      {76555, "iissssipii"},
      {66556, "iisssspiii"},
      {54421, "iiisiispsp"},
      {8863, "iisiiispsp"},
      {9532, "iisiisipsp"},
      {9730, "iisiispsip"},
      {9964, "iisiispspi"},
      {8210, "iisispisip"},
      {7620, "iisispsiip"},
      {7521, "iisispsipi"},
      {7422, "iisispspii"},
      {8821, "iissiiipsp"},
      {8551, "iissipisip"},
      {8542, "iissipispi"},
      {5430, "iissipsiip"},
      {5421, "iissipsipi"},
      {5412, "iissipspii"},
      {8643, "iisspisiip"},
      {8544, "iisspisipi"},
      {8445, "iisspispii"},
      {7432, "iisspsiiip"},
      {7333, "iisspsiipi"},
      {7324, "iisspsipii"},
      {9603, "iiisisddsd"},
      {9799, "iiisisdsdd"},
      {9997, "iiisissddd"},
      {4223, "iiisdsisdd"},
      {6721, "iiissisddd"},
      {6085, "iiissdddsi"},
      {1089, "iisiisddds"},
      {1155, "iisiisddsd"},
      {1223, "iisiisdsdd"},
      {1293, "iisiissddd"},
      {673, "iisisisddd"},
      {485, "iisisdddsi"},
      {171, "iissdddsii"},
      {88, "iiissdddpi"},
      {103684, "iissiisdds"},
      {104328, "iissiisdsd"},
      {104974, "iissiissdd"},
      {84098, "iissisisdd"},
      {82370, "iissisddsi"},
      {39204, "iissddsiis"},
      {38810, "iissddsisi"},
      {38418, "iissddssii"},
      {51528, "iissdsiisd"},
      {50178, "iissdsdsii"},
      {66562, "iisssiisdd"},
      {64518, "iisssddsii"},
      {9809, "iiisisdspd"},
      {4422, "iiisdsisdp"},
      {9739, "iiisdssipd"},
      {9541, "iiisdssdpi"},
      {7622, "iiissisddp"},
      {7631, "iiissisdpd"},
      {7640, "iiissispdd"},
      {9410, "iiissddpsi"},
      {6409, "iiissdsipd"},
      {9656, "iiisssddpi"},
      {6511, "iisiisddsp"},
      {4221, "iisiisdsdp"},
      {5220, "iisiisdspd"},
      {9421, "iisiissddp"},
      {9520, "iisiissdpd"},
      {9619, "iisiisspdd"},
      {3967, "iisiispsdd"},
      {1025, "iisisddpsi"},
      {774, "iisisdsipd"},
      {756, "iisisdsdpi"},
      {1848, "iisisdpisd"},
      {660, "iisissipdd"},
      {633, "iisissddpi"},
      {2807, "iisispisdd"},
      {331, "iissiisdpd"},
      {430, "iissiispdd"},
      {918, "iissisipdd"},
      {873, "iissisddpi"},
      {5182, "iissipisdd"},
      {4762, "iissipddsi"},
      {963, "iissddspii"},
      {1683, "iissddpsii"},
      {721, "iissdsiipd"},
      {424, "iissdsdpii"},
      {2502, "iissdpdsii"},
      {850, "iisssiipdd"},
      {544, "iisssddpii"},
      {3483, "iisspddsii"},
      {110224, "iissiisdps"},
      {185761, "iissiispds"},
      {186623, "iissiispsd"},
      {99840, "iissisisdp"},
      {98542, "iissisdsip"},
      {98443, "iissisdspi"},
      {95521, "iissdsiisp"},
      {77510, "iissdsisip"},
      {76511, "iissdsispi"},
      {76520, "iissdssiip"},
      {66521, "iissdssipi"},
      {65522, "iissdsspii"},
      {66653, "iisssiisdp"},
      {66499, "iisssisipd"},
      {86641, "iisssisdpi"},
      {86552, "iissssiipd"},
      {65555, "iissssdpii"},
      {9863, "iisiispsdp"},
      {9962, "iisiispspd"},
      {9841, "iisisdpisp"},
      {8820, "iisispisdp"},
      {9819, "iisispispd"},
      {7519, "iisispsipd"},
      {991, "iissisipdp"},
      {8531, "iissipisdp"},
      {8540, "iissipispd"},
      {9401, "iissipdspi"},
      {5419, "iissipsipd"},
      {5401, "iissipsdpi"},
      {6320, "iissdpsiip"},
      {6212, "iissdpspii"},
      {8434, "iisspisdpi"},
      {6311, "iisspdsipi"},
      {6302, "iisspdspii"},
      {7331, "iisspsiipd"},
      {4093, "iiisdssddd"},
      {5929, "iiissdddds"},
      {6083, "iiissdddsd"},
      {6239, "iiissddsdd"},
      {6397, "iiissdsddd"},
      {6557, "iiisssdddd"},
      {483, "iisisdddsd"},
      {527, "iisisddsdd"},
      {573, "iisisdsddd"},
      {285, "iissisdddd"},
      {81796, "iissisddds"},
      {82368, "iissisddsd"},
      {82942, "iissisdsdd"},
      {83518, "iississddd"},
      {28900, "iissdddsis"},
      {28562, "iissdddssi"},
      {38808, "iissddsisd"},
      {38026, "iissddsdsi"},
      {51074, "iissdsisdd"},
      {49730, "iissdsddsi"},
      {66046, "iisssisddd"},
      {64010, "iisssdddsi"},
      {9440, "iiisdssddp"},
      {9539, "iiisdssdpd"},
      {9638, "iiisdsspdd"},
      {8640, "iiissdddsp"},
      {7569, "iiissdddps"},
      {9216, "iiissddpds"},
      {9408, "iiissddpsd"},
      {8655, "iiisssdddp"},
      {9654, "iiisssddpd"},
      {6648, "iiisssdpdd"},
      {844, "iisisdddsp"},
      {1023, "iisisddpsd"},
      {1762, "iisisdpsdd"},
      {640, "iisissdpdd"},
      {2701, "iisispsddd"},
      {871, "iissisddpd"},
      {880, "iissisdpdd"},
      {979, "iissispddd"},
      {4624, "iissipddds"},
      {4760, "iissipddsd"},
      {4898, "iissipdsdd"},
      {5038, "iissipsddd"},
      {710, "iissdddsip"},
      {970, "iissddsipd"},
      {1601, "iissddpdsi"},
      {749, "iisssipddd"},
      {3841, "iisspisddd"},
      {3365, "iisspdddsi"},
      {98632, "iissisddsp"},
      {98432, "iissisdsdp"},
      {98441, "iissisdspd"},
      {98531, "iississddp"},
      {85319, "iississdpd"},
      {98830, "iissddsisp"},
      {87431, "iissddssip"},
      {86432, "iissddsspi"},
      {75510, "iissdsisdp"},
      {76509, "iissdsispd"},
      {178929, "iissdsdpis"},
      {178085, "iissdsdpsi"},
      {66519, "iissdssipd"},
      {65421, "iissdssdpi"},
      {76640, "iisssisddp"},
      {86639, "iisssisdpd"},
      {96638, "iisssispdd"},
      {76541, "iisssddsip"},
      {66542, "iisssddspi"},
      {76551, "iissssipdd"},
      {65544, "iissssddpi"},
      {9940, "iiissddpsp"},
      {9664, "iiisssdpdp"},
      {7220, "iisispsddp"},
      {7418, "iisispspdd"},
      {9984, "iissipdsdp"},
      {9399, "iissipdspd"},
      {9530, "iissipsddp"},
      {5399, "iissipsdpd"},
      {5408, "iissipspdd"},
      {8621, "iissddpsip"},
      {8612, "iissddpspi"},
      {5210, "iissdpdsip"},
      {5201, "iissdpdspi"},
      {6219, "iissdpsipd"},
      {6201, "iissdpsdpi"},
      {8432, "iisspisddp"},
      {8441, "iisspispdd"},
      {9026, "iisspddpsi"},
      {6309, "iisspdsipd"},
      {9954, "iisspdsdpi"},
      {9732, "iisspsddpi"},
      {99663, "iisssispdp"},
      {167, "iissdddsdd"},
      {193, "iissddsddd"},
      {251, "iisssddddd"},
      {28224, "iissdddsds"},
      {28560, "iissdddssd"},
      {37636, "iissddsdds"},
      {38024, "iissddsdsd"},
      {38414, "iissddssdd"},
      {49284, "iissdsddds"},
      {49728, "iissdsddsd"},
      {50174, "iissdsdsdd"},
      {50622, "iissdssddd"},
      {63504, "iisssdddds"},
      {64008, "iisssdddsd"},
      {64514, "iisssddsdd"},
      {65022, "iisssdsddd"},
      {65532, "iissssdddd"},
      {861, "iissdddsdp"},
      {900, "iissdddpds"},
      {941, "iissddsddp"},
      {950, "iissddsdpd"},
      {959, "iissddspdd"},
      {1599, "iissddpdsd"},
      {1679, "iissddpsdd"},
      {420, "iissdsdpdd"},
      {519, "iissdspddd"},
      {2498, "iissdpdsdd"},
      {2598, "iissdpsddd"},
      {540, "iisssddpdd"},
      {549, "iisssdpddd"},
      {648, "iissspdddd"},
      {3249, "iisspdddds"},
      {3363, "iisspdddsd"},
      {3479, "iisspddsdd"},
      {3597, "iisspdsddd"},
      {3717, "iisspsdddd"},
      {86521, "iissdddssp"},
      {85431, "iissddssdp"},
      {86430, "iissddsspd"},
      {99742, "iissdsddsp"},
      {177241, "iissdsdpds"},
      {178083, "iissdsdpsd"},
      {65320, "iissdssddp"},
      {65419, "iissdssdpd"},
      {65518, "iissdsspdd"},
      {96400, "iisssdddsp"},
      {65541, "iisssddsdp"},
      {66540, "iisssddspd"},
      {65542, "iissssddpd"},
      {65551, "iissssdpdd"},
      {66550, "iisssspddd"},
      {6100, "iissddpdsp"},
      {8610, "iissddpsdp"},
      {9942, "iissdpdsdp"},
      {5199, "iissdpdspd"},
      {9952, "iissdpsddp"},
      {6199, "iissdpsdpd"},
      {6208, "iissdpspdd"},
      {964, "iissspdddp"},
      {6433, "iisspdddsp"},
      {8430, "iisspddsdp"},
      {9024, "iisspddpsd"},
      {9853, "iisspdsddp"},
      {6298, "iisspdspdd"},
      {8731, "iisspsdddp"},
      {7318, "iisspsdpdd"},
      {96551, "iissdsspdp"}};

  for(auto t : brut){
    int jd = solve(t.first);
    if(jd != t.second.size())
      cout << t.first << "\n";
  }
}