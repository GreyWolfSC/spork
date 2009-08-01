/*
 * gct.h
 * Class to handle Ocarina TXT Cheatfiles
 * nIxx
 */

#include <iostream>
#include <fstream>
#include "gct.h"

#define ERRORRANGE "Error: CheatNr out of range"

GCTCheats::GCTCheats(void) {
    iCntCheats = 0;
}

GCTCheats::~GCTCheats(void) {

    string sGameID ="";
    string sGameTitle = "";
    /*string sCheatName[MAXCHEATS];
    string sCheats[MAXCHEATS];
    string sCheatComment[MAXCHEATS];*/
}

int GCTCheats::getCnt() {
    return iCntCheats;
}

string GCTCheats::getGameName(void) {
    return sGameTitle;
}

string GCTCheats::getGameID(void) {
    return sGameID;
}

string GCTCheats::getCheat(int nr) {
    if (nr <= (iCntCheats-1)) {
        return sCheats[nr];
    } else {
        return ERRORRANGE;
    }
}

string GCTCheats::getCheatName(int nr) {
    if (nr <= (iCntCheats-1)) {
        return sCheatName[nr];
    } else {
        return ERRORRANGE;
    }
}

string GCTCheats::getCheatComment(int nr) {
    if (nr <= (iCntCheats-1)) {
        return sCheatComment[nr];
    } else {
        return ERRORRANGE;
    }
}

int GCTCheats::createGCT(int nr,const char * filename) {
    ofstream filestr;
    filestr.open(filename);

    if (filestr.fail())
        return 0;

    //Header and Footer
    char header[] = { 0x00, 0xd0, 0xc0, 0xde, 0x00, 0xd0, 0xc0, 0xde};
    char footer[] = { 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    string buf = getCheat(nr);
    filestr.write(header,sizeof(header));

    int x = 0;
    long int li;
    int len = buf.size();

    while (x < len) {
        string temp = buf.substr(x,2);
        li = strtol(temp.c_str(),NULL,16);
        temp = li;
        filestr.write(temp.c_str(),1);
        x +=2;
    }
    filestr.write(footer,sizeof(footer));

    filestr.close();
    return 1;
}

int GCTCheats::createGCT(const char * chtbuffer,const char * filename) {
    ofstream filestr;
    filestr.open(filename);

    if (filestr.fail())
        return 0;

    //Header and Footer
    char header[] = { 0x00, 0xd0, 0xc0, 0xde, 0x00, 0xd0, 0xc0, 0xde};
    char footer[] = { 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    string buf = chtbuffer;
    filestr.write(header,sizeof(header));

    int x = 0;
    long int li;
    int len = buf.size();

    while (x < len) {
        string temp = buf.substr(x,2);
        li = strtol(temp.c_str(),NULL,16);
        temp = li;
        filestr.write(temp.c_str(),1);
        x +=2;
    }

    filestr.write(footer,sizeof(footer));

    filestr.close();

    return 1;
}

int GCTCheats::createGCT(int nr[],int cnt,const char * filename) {

    ofstream filestr;
    filestr.open(filename);

    if (filestr.fail())
        return 0;

    //Header and Footer
    char header[] = { 0x00, 0xd0, 0xc0, 0xde, 0x00, 0xd0, 0xc0, 0xde};
    char footer[] = { 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    filestr.write(header,sizeof(header));

    int c = 0;
    while (c != cnt) {
        int actnr = nr[c];
        string buf = getCheat(actnr);
        long int li;
        int len = buf.size();
        int x = 0;

        while (x < len) {
            string temp = buf.substr(x,2);
            li = strtol(temp.c_str(),NULL,16);
            temp = li;
            filestr.write(temp.c_str(),1);
            x +=2;
        }
        c++;
    }

    filestr.write(footer,sizeof(footer));
    filestr.close();
    return 1;
}

int GCTCheats::openTxtfile(const char * filename) {
    ifstream filestr;
    int i = 0;
    string str;
    filestr.open(filename);

    if (filestr.fail())
        return 0;

    filestr.seekg(0,ios_base::end);
    int size = filestr.tellg();
    if (size <= 0) return -1;
    filestr.seekg(0,ios_base::beg);

    getline(filestr,sGameID);
    getline(filestr,sGameTitle);
    filestr.ignore();

    while (!filestr.eof()) {
        getline(filestr,sCheatName[i]);
        string cheatdata;
        bool emptyline = false;
        bool isComment = false;

        do {
            getline(filestr,str,'\n');
            //cheatdata.append(str);

            if (str == "") {
                emptyline = true;
                break;
            }

            if (str.size() <= 16 || str.size() > 17 ) {
                isComment = true;
                printf ("%i",str.size());
            }

            if (!isComment) {
                cheatdata.append(str);
                size_t found=cheatdata.find(' ');
                cheatdata.replace(found,1,"");
            } else {
                sCheatComment[i] = str;
            }

            if (filestr.eof()) break;
        } while (!emptyline);

        sCheats[i] = cheatdata;
        i++;
    }
    iCntCheats = i;
    filestr.close();
    return 1;
}