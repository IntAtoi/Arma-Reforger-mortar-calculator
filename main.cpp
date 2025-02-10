#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct BallisticData0 {
    float range;
    float elevation;
};
struct BallisticData1 {
    float range;
    float elevation;
};
struct BallisticData2 {
    float range;
    float elevation;
};
struct BallisticData3 {
    float range;
    float elevation;
};
struct BallisticData4 {
    float range;
    float elevation;
};


float interpolate(float x1, float y1, float x2, float y2, float x) {
    return y1 + (y2 - y1) * (x - x1) / (x2 - x1);
}

template <typename BallisticData>
float findElevation(const vector<BallisticData>& table, float range) {
    for (size_t i = 0; i < table.size() - 1; ++i) {
        if (range >= table[i].range && range <= table[i + 1].range) {
            return interpolate(
                    table[i].range, table[i].elevation,
                    table[i + 1].range, table[i + 1].elevation,
                    range
            );
        }
    }
    cout << "Inappropriate distance\n";
    return -1;
}

float distance(float x1, float y1, float x2, float y2) {
    do {
        cout << "Mortar position\n";
        cout << "Insert x:";
        cin >> x1;
        if (x1 < 0) cout << "Value cannot be negative\n";
    } while (x1 < 0);

    do {
        cout << "Insert y:";
        cin >> y1;
        if (y1 < 0) cout << "Value cannot be negative\n";
    } while (y1 < 0);

    do {
        cout << "Target position\n";
        cout << "Insert x:";
        cin >> x2;
        if (x2 < 0) cout << "Value cannot be negative\n";
    } while (x2 < 0);

    do {
        cout << "Insert y:";
        cin >> y2;
        if (y2 < 0) cout << "Value cannot be negative\n";
    } while (y2 < 0);

    float range = ((sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2))) * 100);
    cout << "Distance: " << range << " meters\n";
    return range;
}

int main() {

    float x1, y1, x2, y2;
    short menu;
    short shellTypeUSSR;
    short shellTypeUS;

//US HE
    vector<BallisticData0> he_ballisticTable0 = {
            {50, 1540}, {100, 1479}, {150, 1416}, {200, 1350},
            {250, 1279}, {300, 1201}, {350, 1106}, {400, 955}
    };
    vector<BallisticData1> he_ballisticTable1 = {
            {100, 1574}, {200, 1492}, {300, 1437}, {400, 1378},
            {500, 1317}, {600, 1249}, {700, 1174}, {800, 1085},
            {900, 954}
    };
    vector<BallisticData2> he_ballisticTable2 = {
            {200, 1538}, {300, 1507}, {400, 1475}, {500, 1443},
            {600, 1410}, {700, 1376}, {800, 1341}, {900, 1305},
            {1000, 1266}, {1100, 1225}, {1200, 1180}, {1300, 1132},
            {1400, 1076}, {1500, 1009}, {1600, 912}
    };
    vector<BallisticData3> he_ballisticTable3 = {
            {300, 1534}, {400, 1511}, {500, 1489}, {600, 1466},
            {700, 1442}, {800, 1419}, {900, 1395}, {1000, 1370},
            {1100, 1344}, {1200, 1318}, {1300, 1391}, {1400, 1363},
            {1500, 1233}, {1600, 1202}, {1700, 1169}, {1800, 1133},
            {1900, 1094}, {2000, 1051}, {2100, 999}, {2200, 931},
            {2300, 801}
    };
    vector<BallisticData4> he_ballisticTable4 = {
            {400, 1531}, {500, 1514}, {600, 1496}, {700, 1478},
            {800, 1460}, {900, 1442}, {1000, 1424}, {1100, 1405},
            {1200, 1385}, {1300, 1366}, {1400, 1346}, {1500, 1326},
            {1600, 1305}, {1700, 1283}, {1800, 1261}, {1900, 1238},
            {2000, 1214}, {2100, 1188}, {2200, 1162}, {2300, 1134},
            {2400, 1105}, {2500, 1075}, {2600, 1044}, {2700, 1012},
            {2800, 993}, {2900, 870}
    };

    //US SMOKE
    vector<BallisticData1> smoke_ballisticTable1 = {
            {150, 1498},
            {200, 1463}, {250, 1427}, {300, 1391}, {350, 1352},
            {400, 1314}, {450, 1271}, {500, 1227}, {550, 1178},
            {600, 1124}, {650, 1060}, {700, 982}, {750, 822}
    };

    vector<BallisticData2> smoke_ballisticTable2 = {
            {200, 1528}, {300, 1491}, {400, 1453}, {500, 1414},
            {600, 1374}, {700, 1333}, {800, 1289}, {900, 1242},
            {1000, 1191}, {1100, 1133}, {1200, 1067}, {1300, 980},
            {1400, 818}
    };
    vector<BallisticData3> smoke_ballisticTable3 = {
            {300, 1522}, {400, 1495}, {500, 1468}, {600, 1440},
            {700, 1412}, {800, 1383}, {900, 1354}, {1000, 1323},
            {1100, 1291}, {1200, 1257}, {1300, 1221}, {1400, 1183},
            {1500, 1142}, {1600, 1096}, {1700, 1044}, {1800, 980},
            {1900, 892}
    };
    vector<BallisticData4> smoke_ballisticTable4 = {
            {400, 1517}, {500, 1495}, {600, 1474}, {700, 1452},
            {800, 1429}, {900, 1407}, {1000, 1383}, {1100, 1360},
            {1200, 1335}, {1300, 1310}, {1400, 1284}, {1500, 1257},
            {1600, 1228}, {1700, 1199}, {1800, 1166}, {1900, 1132},
            {2000, 1096}, {2100, 1055}, {2200, 1008}, {2300, 952},
            {2400, 871}
    };


    //USSR HE
    vector<BallisticData0> he_ballisticTable0S = {
            {50, 1455}, {100, 1411}, {150, 1365}, {200, 1318},
            {250, 1268}, {300, 1217}, {350, 1159}, {400, 1095},
            {450, 1023}, {500, 922}
    };
    vector<BallisticData1> he_ballisticTable1S = {
            {100, 1446}, {200, 1392}, {300, 1335}, {400, 1275},
            {500, 1212}, {600, 1141}, {700, 1058}, {800, 952}
    };
    vector<BallisticData2> he_ballisticTable2S = {
            {200, 1432}, {300, 1397}, {400, 1362}, {500, 1325},
            {600, 1288}, {700, 1248}, {800, 1207}, {900, 1162},
            {1000, 1114}, {1100, 1060}, {1200, 997}, {1300, 914},
            {1400, 755}
    };
    vector<BallisticData3> he_ballisticTable3S = {
            {300, 1423}, {400, 1397}, {500, 1370}, {600, 1343},
            {700, 1315}, {800, 1286}, {900, 1257}, {1000, 1226},
            {1100, 1193}, {1200, 1159}, {1300, 1123}, {1400, 1084},
            {1500, 1040}, {1600, 991}, {1700, 932}, {1800, 851}
    };
    vector<BallisticData4> he_ballisticTable4S = {
            {400, 1418}, {500, 1398}, {600, 1376}, {700, 1355},
            {800, 1333}, {900, 1311}, {1000, 1288}, {1100, 1264},
            {1200, 1240}, {1300, 1366}, {1400, 1346}, {1500, 1326},
            {1600, 1305}, {1700, 1283}, {1800, 1261}, {1900, 1238},
            {2000, 1214}, {2100, 1188}, {2200, 1162}, {2300, 1134}
    };

    //USSR SMOKE
    vector<BallisticData4> smoke_ballisticTable0S = {
            {50, 1450}, {100, 1399}, {150, 1347}, {200, 1292},
            {250, 1235}, {300, 1172}, {350, 1102}, {400, 1020},
            {450, 892}
    };
    vector<BallisticData4> smoke_ballisticTable1S = {
            {200, 1381}, {300, 1319}, {400, 1252}, {500, 1179},
            {600, 1097}, {700, 993}, {800, 805}
    };
    vector<BallisticData4> smoke_ballisticTable2S = {
            {300, 1387}, {400, 1348}, {500, 1308}, {600, 1266},
            {700, 1222}, {800, 1175}, {900, 1123}, {1000, 1065},
            {1100, 994}, {1200, 902}
    };
    vector<BallisticData4> smoke_ballisticTable3S = {
            {400, 1387}, {500, 1357}, {600, 1327}, {700, 1296},
            {800, 1264}, {900, 1231}, {1000, 1196}, {1100, 1159},
            {1200, 1119}, {1300, 1075}, {1400, 1026}, {1500, 969},
            {1600, 896}, {1700, 753}
    };

    marker:
    cout << "Select mortar\n";
    cout << "1 - US\n";
    cout << "2 - USSR\n";
    cin >> menu;

    switch (menu) {
        case 2: {
            markerShellUSSR:
            cout << "Select shell type\n";
            cout << "1 - HE\n";
            cout << "2 - SMOKE\n";
            cin >> shellTypeUSSR;

            switch (shellTypeUSSR) {
                case 1: {
                    markerUSSRcoordsHE:
                    float range = distance(x1, y1, x2, y2);
                    if (range >= 50 && range < 500) {
                        float elevation = findElevation(he_ballisticTable0S, range);
                        if (elevation != -1) {
                            cout << "Elevation: " << elevation << " mils (0 rings)\n";
                        }
                    }
                    if (range >= 500 && range < 800) {
                        float elevation = findElevation(he_ballisticTable1S, range);
                        if (elevation != -1) {
                            cout << "Elevation: " << elevation << " mils (1 ring)\n";
                        }
                    }
                    if (range >= 800 && range < 1400) {
                        float elevation = findElevation(he_ballisticTable2S, range);
                        if (elevation != -1) {
                            cout << "Elevation: " << elevation << " mils (2 rings)\n";
                        }
                    }
                    if (range >= 1400 && range < 1800) {
                        float elevation = findElevation(he_ballisticTable3S, range);
                        cout << "Elevation: " << elevation << " mils (3 rings)\n";
                    }
                    if (range >= 1800 && range <= 2300) {
                        float elevation = findElevation(he_ballisticTable4S, range);
                        cout << "Elevation: " << elevation << " mils (4 rings)\n";
                    }
                    if (range < 50 || range > 2300) {
                        cout << "Inappropriate distance\n";
                    }
                    break;
                }
                case 2: {
                    markerUSSRcoordsSMOKE:
                    float range = distance(x1, y1, x2, y2);
                    if (range >= 50 && range < 400) {
                        float elevation = findElevation(smoke_ballisticTable0S, range);
                        if (elevation != -1) {
                            cout << "Elevation: " << elevation << " mils (0 rings)\n";
                        }
                    }
                    if (range >= 400 && range < 800) {
                        float elevation = findElevation(smoke_ballisticTable1S, range);
                        if (elevation != -1) {
                            cout << "Elevation: " << elevation << " mils (1 ring)\n";
                        }
                    }
                    if (range >= 800 && range < 1200) {
                        float elevation = findElevation(smoke_ballisticTable2S, range);
                        if (elevation != -1) {
                            cout << "Elevation: " << elevation << " mils (2 rings)\n";
                        }
                    }
                    if (range >= 1200 && range < 1700) {
                        float elevation = findElevation(smoke_ballisticTable3S, range);
                        cout << "Elevation: " << elevation << " mils (3 rings)\n";
                    }
                    if (range < 50 || range > 1700) {
                        cout << "Inappropriate distance\n";
                    }
                    break;
                }
                default: {
                    cout << "Invalid command\n";
                    goto markerShellUSSR;
                }
            }
            break;
        }
        case 1: {
            markerShellUS:
            cout << "Select shell type\n";
            cout << "1 - HE\n";
            cout << "2 - SMOKE\n";
            cin >> shellTypeUS;

            switch (shellTypeUS) {
                case 1: {
                    markerUScoordsHE:
                    float range = distance(x1, y1, x2, y2);
                    if (range >= 50 && range < 400) {
                        float elevation = findElevation(he_ballisticTable0, range);
                        if (elevation != -1) {
                            cout << "Elevation: " << elevation << " mils (0 rings)\n";
                        }
                    }
                    if (range >= 400 && range < 900) {
                        float elevation = findElevation(he_ballisticTable1, range);
                        if (elevation != -1) {
                            cout << "Elevation: " << elevation << " mils (1 ring)\n";
                        }
                    }
                    if (range >= 900 && range < 1600) {
                        float elevation = findElevation(he_ballisticTable2, range);
                        if (elevation != -1) {
                            cout << "Elevation: " << elevation << " mils (2 rings)\n";
                        }
                    }
                    if (range >= 1600 && range < 2300) {
                        float elevation = findElevation(he_ballisticTable3, range);
                        cout << "Elevation: " << elevation << " mils (3 rings)\n";
                    }
                    if (range >= 2300 && range <= 2900) {
                        float elevation = findElevation(he_ballisticTable4, range);
                        cout << "Elevation: " << elevation << " mils (4 rings)\n";
                    }
                    if (range < 50 || range > 2900) {
                        cout << "Inappropriate distance\n";
                    }
                    break;
                }
                case 2: {
                    markerUScoordsSMOKE:
                    float range = distance(x1, y1, x2, y2);
                    if (range >= 150 && range <= 750) {
                        float elevation = findElevation(smoke_ballisticTable1, range);
                        if (elevation != -1) {
                            cout << "Elevation: " << elevation << " mils (1 ring)\n";
                        }
                    }
                    if (range >= 800 && range < 1400) {
                        float elevation = findElevation(smoke_ballisticTable2, range);
                        if (elevation != -1) {
                            cout << "Elevation: " << elevation << " mils (2 rings)\n";
                        }
                    }
                    if (range >= 1400 && range < 1900) {
                        float elevation = findElevation(smoke_ballisticTable3, range);
                        if (elevation != -1) {
                            cout << "Elevation: " << elevation << " mils (3 rings)\n";
                        }
                    }
                    if (range >= 1900 && range < 2400) {
                        float elevation = findElevation(smoke_ballisticTable4, range);
                        cout << "Elevation: " << elevation << " mils (4 rings)\n";
                    }
                    if (range < 150 || range > 2400) {
                        cout << "Inappropriate distance\n";
                    }
                    break;
                }
                default: {
                    cout << "Invalid command\n";
                    goto markerShellUS;
                }
            }
            break;
        }
        default: {
            cout << "Invalid command\n";
            break;
        }
    }

    short menu1;
    menuMarker1:
    cout << "1 - Change coordinates\n";
    cout << "2 - To start\n";
    cout << "3 - Exit\n";
    cin >> menu1;

    switch (menu1) {
        case 2: {
            goto marker;
        }
        case 3: {
            return 0;
        }
        case 1: {
            switch (menu) {
                case 1: {
                    switch (shellTypeUS) {
                        case 1: {
                            goto markerUScoordsHE;
                        }
                        case 2: {
                            goto markerUScoordsSMOKE;
                        }
                    }
                }
                case 2: {
                    switch (shellTypeUSSR) {
                        case 1: {
                            goto markerUSSRcoordsHE;
                        }
                        case 2: {
                            goto markerUSSRcoordsSMOKE;
                        }
                    }
                }
            }
        }
        default: {
            cout << "Invalid command\n";
            goto menuMarker1;
        }
    }
}
