/****************************************************************************
 * libwiigui
 *
 * Tantric 2009
 *
 * gui_keyboard.cpp
 *
 * GUI class definitions
 ***************************************************************************/

#include "gui.h"
#include "../main.h"
#include "../settings/CSettings.h"
#include <stdio.h>
#include <string.h>
#include "menu.h"
/**
 * Constructor for the GuiKeyboard class.
 */
unsigned int m;
//const Key thekeys;
GuiKeyboard::GuiKeyboard(char * t, u32 max, int min, int lang)
{
    width = 540;
    height = 400;
    shift = 0;
    caps = 0;
    alt = 0;
    alt2 = 0;
    m = min;
    int mode = lang;
    selectable = true;
    focus = 0; // allow focus
    alignmentHor = ALIGN_CENTRE;
    alignmentVert = ALIGN_MIDDLE;
    kbtextmaxlen = max > sizeof(kbtextstr) ? sizeof(kbtextstr) : max; // limit max up to sizeof(kbtextstr)
    //  strlcpy(kbtextstr, t, kbtextmaxlen);
    strncpy(kbtextstr, t, kbtextmaxlen); // strncpy is needed to fill the rest with \0
    kbtextstr[sizeof(kbtextstr) - 1] = 0; // terminate with \0
    //QWERTY//
    if (mode == 0)
    {
        Key thekeys[4][11] = { { { '1', '!' }, { '2', '@' }, { '3', '#' }, { '4', '$' }, { '5', '%' }, { '6', '^' }, {
                '7', '&' }, { '8', '*' }, { '9', '(' }, { '0', ')' }, { '\0', '\0' } }, { { 'q', 'Q' }, { 'w', 'W' }, {
                'e', 'E' }, { 'r', 'R' }, { 't', 'T' }, { 'y', 'Y' }, { 'u', 'U' }, { 'i', 'I' }, { 'o', 'O' }, { 'p',
                'P' }, { '-', '_' } }, { { 'a', 'A' }, { 's', 'S' }, { 'd', 'D' }, { 'f', 'F' }, { 'g', 'G' }, { 'h',
                'H' }, { 'j', 'J' }, { 'k', 'K' }, { 'l', 'L' }, { ':', ';' }, { '\'', '"' } },

        { { 'z', 'Z' }, { 'x', 'X' }, { 'c', 'C' }, { 'v', 'V' }, { 'b', 'B' }, { 'n', 'N' }, { 'm', 'M' },
                { ',', '<' }, { '.', '>' }, { '/', '?' }, { '\0', '\0' } } };

        memcpy(keys, thekeys, sizeof(thekeys));
    }
    //DVORAK//
    if (mode == 1)
    {
        Key thekeys[4][11] = { { { '1', '!', '\0' }, { '2', '@', '\0' }, { '3', '#', '\0' }, { '4', '$', '\0' }, { '5',
                '%', '\0' }, { '6', '^', '\0' }, { '7', '&', '\0' }, { '8', '*', '\0' }, { '9', '(', '\0' }, { '0',
                ')', '\0' }, { '\0', '\0', '\0' } }, { { '\'', '"', '\0' }, { ',', '<', '\0' }, { '.', '>', '\0' }, {
                'p', 'P', '\0' }, { 'y', 'Y', '\0' }, { 'f', 'F', '\0' }, { 'g', 'G', '\0' }, { 'c', 'C', '\0' }, {
                'r', 'R', '\0' }, { 'l', 'L', '\0' }, { '/', '?', '\0' } }, { { 'a', 'A', 'm' }, { 'o', 'O', 'm' }, {
                'e', 'E', 'm' }, { 'u', 'U', 'm' }, { 'i', 'I', 'm' }, { 'd', 'D', 'm' }, { 'h', 'H', 'm' }, { 't',
                'T', 'm' }, { 'n', 'N', 'm' }, { 's', 'S', 'm' }, { '-', '_', 'm' } },

        { { ';', ':', '\0' }, { 'q', 'Q', '\0' }, { 'j', 'J', '\0' }, { 'k', 'K', '\0' }, { 'x', 'X', '\0' }, { 'b',
                'B', '\0' }, { 'm', 'M', '\0' }, { 'w', 'W', '\0' }, { 'v', 'V', '\0' }, { 'z', 'Z', '\0' }, { '\0',
                '\0', '\0' } } };
        memcpy(keys, thekeys, sizeof(thekeys));
    }
    //QWETRZ//
    if (mode == 2)
    {
        Key thekeys[4][11] = { { { '1', '!', '^', '�' }, { '2', '"', '�', '�' }, { '3', '#', '�', '�' }, { '4', '$',
                '�', '�' }, { '5', '%', '�', '�' }, { '6', '&', '�', '�' }, { '7', '/', '�', '�' }, { '8', '(', '[',
                '�' }, { '9', ')', ']', '�' }, { '0', '=', '�', '�' }, { '�', '?', '\'', '�' } }, { { 'q', 'Q', '@',
                '�' }, { 'w', 'W', '\0', '�' }, { 'e', 'E', '�', '�' }, { 'r', 'R', '\0', '�' },
                { 't', 'T', '\0', '�' }, { 'z', 'Z', '\0', '�' }, { 'u', 'U', '\0', '�' }, { 'i', 'I', '\0', '�' }, {
                        'o', 'O', '\0', '�' }, { 'p', 'P', '\0', '�' }, { '�', '�', '\0', '�' } }, { { 'a', 'A', '\0',
                '�' }, { 's', 'S', '\0', '�' }, { 'd', 'D', '\0', '�' }, { 'f', 'F', '\0', '�' },
                { 'g', 'G', '\0', '�' }, { 'h', 'H', '\0', '�' }, { 'j', 'J', '\0', '�' }, { 'k', 'K', '\0', '�' }, {
                        'l', 'L', '\0', '�' }, { '�', '�', '\0', '�' }, { '�', '�', '\0', '�' } }, { { '<', '>', '|',
                '�' }, { 'y', 'Y', '\0', '�' }, { 'x', 'X', '\0', '�' }, { 'c', 'C', '�', '�' },
                { 'v', 'V', '�', '�' }, { 'b', 'B', '\0', '�' }, { 'n', 'N', '\0', '�' }, { 'm', 'M', '�', '�' }, {
                        ',', ';', '\0', '�' }, { '.', ':', '\0', '\0' }, { '-', '_', '\0', '\0' } } };
        memcpy(keys, thekeys, sizeof(thekeys));
    }
    //AZERTY//
    if (mode == 3)
    {
        Key thekeys[4][11] = { { { '1', '&', '�', '�' }, { '2', '~', '�', '�' }, { '3', '"', '#', '�' }, { '4', '`',
                '�', '�' }, { '5', '(', '[', '�' }, { '6', '-', '|', '�' }, { '7', '�', '�', '�' }, { '8', '_', '\'',
                '�' }, { '9', '+', '^', '�' }, { '0', '=', '@', '�' }, { '�', ')', ']', '�' } }, {
                { 'a', 'A', '�', '�' }, { 'z', 'Z', '�', '�' }, { 'e', 'E', '�', '�' }, { 'r', 'R', '�', '�' }, { 't',
                        'T', '�', '�' }, { 'y', 'Y', '�', '�' }, { 'u', 'U', '�', '�' }, { 'i', 'I', '�', '�' }, { 'o',
                        'O', '�', '�' }, { 'p', 'P', '�', '�' }, { '$', '�', '�', '�' } }, { { 'q', 'Q', '�', '�' }, {
                's', 'S', '�', '�' }, { 'd', 'D', '\0', '�' }, { 'f', 'F', '�', '�' }, { 'g', 'G', '\0', '�' }, { 'h',
                'H', '\0', '�' }, { 'j', 'J', '\0', '�' }, { 'k', 'K', '\0', '�' }, { 'l', 'L', '\0', '�' }, { 'm',
                'M', '\0', '�' }, { '*', '%', '�', '�' } }, { { '<', '>', '\0', '�' }, { 'w', 'W', '\0', '�' }, { 'x',
                'X', '\0', '�' }, { 'c', 'C', '�', '�' }, { 'v', 'V', '�', '�' }, { 'b', 'B', '�', '�' }, { 'n', 'N',
                '\0', '�' }, { '?', ',', '?', '�' }, { '.', ';', '.', '�' }, { '/', ':', '/', '�' }, { '�', '!', '!',
                '�' } } };
        memcpy(keys, thekeys, sizeof(thekeys));
    }
    //QWERTY 2//
    if (mode == 4)
    {
        Key thekeys[4][11] = { { { '1', '!', '|', '�' }, { '2', '"', '@', '�' }, { '3', '�', '#', '�' }, { '4', '$',
                '�', '�' }, { '5', '%', '~', '�' }, { '6', '&', '�', '�' }, { '7', '/', '\'', '�' }, { '8', '(', '[',
                '�' }, { '9', ')', ']', '�' }, { '0', '=', '�', '�' }, { '�', '?', '�', '�' } }, { { 'q', 'Q', '\0',
                '�' }, { 'w', 'W', '\0', '�' }, { 'e', 'E', '�', '�' }, { 'r', 'R', '�', '�' }, { 't', 'T', '�', '�' },
                { 'y', 'Y', '�', '�' }, { 'u', 'U', '�', '�' }, { 'i', 'I', '�', '�' }, { 'o', 'O', '�', '�' }, { 'p',
                        'P', '�', '�' }, { '+', '*', '\0', '�' } }, { { 'a', 'A', '^', '�' }, { 's', 'S', '�', '�' }, {
                'd', 'D', '�', '�' }, { 'f', 'F', '�', '�' }, { 'g', 'G', '�', '�' }, { 'h', 'H', '�', '�' }, { 'j',
                'J', '�', '�' }, { 'k', 'K', '�', '�' }, { 'l', 'L', '�', '\0' }, { '�', '�', '+', '\0' }, { '�', '�',
                '�', '\0' } }, { { '<', '>', '\0', '�' }, { 'z', 'Z', '\0', '�' }, { 'x', 'X', '\0', '�' }, { 'c', 'C',
                '�', '�' }, { 'v', 'V', '\0', '�' }, { 'b', 'B', '�', '�' }, { 'n', 'N', '\0', '�' }, { 'm', 'M', '\0',
                '�' }, { ',', ';', '\0', '�' }, { '.', ':', '\0', '\0' }, { '-', '_', '\0', '\0' } } };
        memcpy(keys, thekeys, sizeof(thekeys));
    }

    keyTextbox = new GuiImageData(keyboard_textbox_png, keyboard_textbox_png_size);
    keyTextboxImg = new GuiImage(keyTextbox);
    keyTextboxImg->SetAlignment(ALIGN_CENTRE, ALIGN_TOP);
    keyTextboxImg->SetPosition(0, 40);//(0,0);
    this->Append(keyTextboxImg);

    kbText = new GuiText(kbtextstr, 20, ( GXColor )
    {   0, 0, 0, 0xff});
    kbText->SetAlignment(ALIGN_CENTRE, ALIGN_TOP);
    kbText->SetPosition(0, 53);//(0, 13);
    this->Append(kbText);

    key = new GuiImageData(keyboard_key_png, keyboard_key_png_size);
    keyOver = new GuiImageData(keyboard_key_over_png, keyboard_key_over_png_size);
    keyMedium = new GuiImageData(keyboard_mediumkey_over_png, keyboard_mediumkey_over_png_size);
    keyMediumOver = new GuiImageData(keyboard_mediumkey_over_png, keyboard_mediumkey_over_png_size);
    keyLarge = new GuiImageData(keyboard_largekey_over_png, keyboard_largekey_over_png_size);
    keyLargeOver = new GuiImageData(keyboard_largekey_over_png, keyboard_largekey_over_png_size);

    trigA = new GuiTrigger;
    trigA->SetSimpleTrigger(-1, WPAD_BUTTON_A | WPAD_CLASSIC_BUTTON_A, PAD_BUTTON_A);
    trigB = new GuiTrigger;
    trigB->SetButtonOnlyTrigger(-1, WPAD_BUTTON_B | WPAD_CLASSIC_BUTTON_B, PAD_BUTTON_B);

    int eurocheck = 0;
    if (mode > 1)
    {
        eurocheck = -20;
    }

    keyBackImg = new GuiImage(keyMedium);
    keyBackOverImg = new GuiImage(keyMediumOver);
    if (mode == 3)
    {
        keyBackText = new GuiText("Retour", 20, ( GXColor )
        {   0, 0, 0, 0xff});
    }
    else
    {
        keyBackText = new GuiText("Back", 20, ( GXColor )
        {   0, 0, 0, 0xff});
    }
    //keyBack = new GuiButton(keyMedium->GetWidth(), keyMedium->GetHeight());
    keyBack = new GuiButton(keyBackImg, keyBackOverImg, 0, 3, 11 * 42 + 40 + eurocheck, 0 * 42 + 120, trigA,
            btnSoundOver, btnSoundClick, 1);
    //keyBack->SetImage(keyBackImg);
    //keyBack->SetImageOver(keyBackOverImg);
    keyBack->SetLabel(keyBackText);
    //keyBack->SetSoundOver(keySoundOver);
    //keyBack->SetSoundClick(keySoundClick);
    //keyBack->SetTrigger(trigA);
    keyBack->SetTrigger(trigB);
    if (mode > 1)
    {
        keyBack->SetPosition(11 * 42 + 40 + eurocheck, 0 * 42 + 120);
    }
    else
    {
        keyBack->SetPosition(10 * 42 + 40 + eurocheck, 0 * 42 + 120);
    }//(10*42+40, 0*42+80);
    //keyBack->SetEffectGrow();
    this->Append(keyBack);

    keyClearImg = new GuiImage(keyMedium);
    keyClearOverImg = new GuiImage(keyMediumOver);
    if (mode == 3)
    {
        keyClearText = new GuiText("Effacer", 20, ( GXColor )
        {   0, 0, 0, 0xff});
    }
    else
    {
        keyClearText = new GuiText("Clear", 20, ( GXColor )
        {   0, 0, 0, 0xff});
    }
    keyClear = new GuiButton(keyClearImg, keyClearOverImg, 0, 3, (10 * 42 + 40) + eurocheck, 4 * 42 + 120, trigA,
            keySoundOver, keySoundClick, 1);
    //keyClear = new GuiButton(keyMedium->GetWidth(), keyMedium->GetHeight());
    //keyClear->SetImage(keyClearImg);
    //keyClear->SetImageOver(keyClearOverImg);
    keyClear->SetLabel(keyClearText);
    //keyClear->SetSoundOver(keySoundOver);
    //keyClear->SetSoundClick(keySoundClick);
    //keyClear->SetTrigger(trigA);
    //keyClear->SetPosition((10*42+40)+eurocheck, 4*42+120);//(10*42+40, 0*42+80);
    //keyClear->SetEffectGrow();
    this->Append(keyClear);

    keyAltImg = new GuiImage(keyMedium);
    keyAltOverImg = new GuiImage(keyMediumOver);
    keyAltText = new GuiText("Alt Gr", 20, ( GXColor )
    {   0, 0, 0, 0xff});
    keyAlt = new GuiButton(keyAltImg, keyAltOverImg, 0, 3, 84 + eurocheck, 4 * 42 + 120, trigA, keySoundOver,
            keySoundClick, 1);
    //keyAlt = new GuiButton(keyMedium->GetWidth(), keyMedium->GetHeight());
    //keyAlt->SetImage(keyAltImg);
    //keyAlt->SetImageOver(keyAltOverImg);
    keyAlt->SetLabel(keyAltText);
    //keyAlt->SetSoundOver(keySoundOver);
    //keyAlt->SetSoundClick(keySoundClick);
    //keyAlt->SetTrigger(trigA);
    //keyAlt->SetPosition(84+eurocheck, 4*42+120);//(10*42+40, 4*42+120);
    //keyAlt->SetEffectGrow();
    if (mode > 1)
    {
        this->Append(keyAlt);
    }

    keyAlt2Img = new GuiImage(keyMedium);
    keyAlt2OverImg = new GuiImage(keyMediumOver);
    keyAlt2Text = new GuiText("Accent", 20, ( GXColor )
    {   0, 0, 0, 0xff});
    keyAlt2 = new GuiButton(keyAlt2Img, keyAlt2OverImg, 0, 3, (8 * 42 + 40) + eurocheck, 4 * 42 + 120, trigA,
            keySoundOver, keySoundClick, 1);
    //keyAlt2 = new GuiButton(keyMedium->GetWidth(), keyMedium->GetHeight());
    //keyAlt2->SetImage(keyAlt2Img);
    //keyAlt2->SetImageOver(keyAlt2OverImg);
    keyAlt2->SetLabel(keyAlt2Text);
    //keyAlt2->SetSoundOver(keySoundOver);
    //keyAlt2->SetSoundClick(keySoundClick);
    //keyAlt2->SetTrigger(trigA);
    //keyAlt2->SetPosition((8*42+40)+eurocheck, 4*42+120);//(10*42+40, 4*42+120);
    //keyAlt2->SetEffectGrow();
    if (mode > 1)
    {
        this->Append(keyAlt2);
    }

    keyCapsImg = new GuiImage(keyMedium);
    keyCapsOverImg = new GuiImage(keyMediumOver);
    keyCapsText = new GuiText("Caps", 20, ( GXColor )
    {   0, 0, 0, 0xff});
    keyCaps = new GuiButton(keyCapsImg, keyCapsOverImg, 0, 3, 0 + eurocheck, 2 * 42 + 120, trigA, keySoundOver,
            keySoundClick, 1);
    //keyCaps = new GuiButton(keyMedium->GetWidth(), keyMedium->GetHeight());
    //keyCaps->SetImage(keyCapsImg);
    //keyCaps->SetImageOver(keyCapsOverImg);
    keyCaps->SetLabel(keyCapsText);
    //keyCaps->SetSoundOver(keySoundOver);
    //keyCaps->SetSoundClick(keySoundClick);
    //keyCaps->SetTrigger(trigA);
    //keyCaps->SetPosition(0+eurocheck, 2*42+120);//(0, 2*42+80);
    //keyCaps->SetEffectGrow();
    this->Append(keyCaps);

    keyShiftImg = new GuiImage(keyMedium);
    keyShiftOverImg = new GuiImage(keyMediumOver);
    keyShiftText = new GuiText("Shift", 20, ( GXColor )
    {   0, 0, 0, 0xff});
    keyShift = new GuiButton(keyShiftImg, keyShiftOverImg, 0, 3, 21 + eurocheck, 3 * 42 + 120, trigA, keySoundOver,
            keySoundClick, 1);
    //keyShift = new GuiButton(keyMedium->GetWidth(), keyMedium->GetHeight());
    //keyShift->SetImage(keyShiftImg);
    //keyShift->SetImageOver(keyShiftOverImg);
    keyShift->SetLabel(keyShiftText);
    //keyShift->SetSoundOver(keySoundOver);
    //keyShift->SetSoundClick(keySoundClick);
    //keyShift->SetTrigger(trigA);
    //keyShift->SetPosition(21+eurocheck, 3*42+120);//(21, 3*42+80);
    //keyShift->SetEffectGrow();
    this->Append(keyShift);

    keySpaceImg = new GuiImage(keyLarge);
    keySpaceOverImg = new GuiImage(keyLargeOver);
    keySpace = new GuiButton(keySpaceImg, keySpaceOverImg, 2, 3, 0 + eurocheck, 4 * 42 + 120, trigA, keySoundOver,
            keySoundClick, 1);
    //keySpace = new GuiButton(keyLarge->GetWidth(), keyLarge->GetHeight());
    //keySpace->SetImage(keySpaceImg);
    //keySpace->SetImageOver(keySpaceOverImg);
    //keySpace->SetSoundOver(keySoundOver);
    //keySpace->SetSoundClick(keySoundClick);
    //keySpace->SetTrigger(trigA);
    //keySpace->SetPosition(0+eurocheck, 4*42+120);//(0, 4*42+80);
    //keySpace->SetAlignment(ALIGN_CENTRE, ALIGN_TOP);
    //keySpace->SetEffectGrow();
    this->Append(keySpace);

    char txt[2] = { 0, 0 };
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (keys[i][j].ch != '\0')
            {
                keyImg[i][j] = new GuiImage(key);
                keyImgOver[i][j] = new GuiImage(keyOver);
                txt[0] = keys[i][j].ch;
                keyTxt[i][j] = new GuiText(txt, 20, ( GXColor )
                {   0, 0, 0, 0xff});
                keyTxt[i][j]->SetAlignment(ALIGN_CENTRE, ALIGN_BOTTOM);
                keyTxt[i][j]->SetPosition(0, -10);
                keyBtn[i][j] = new GuiButton(keyImg[i][j], keyImgOver[i][j], 0, 3, (j * 42 + 21 * i + 40) + eurocheck,
                        i * 42 + 120, trigA, keySoundOver, keySoundClick, 1);
                //keyBtn[i][j] = new GuiButton(key->GetWidth(), key->GetHeight());
                //keyBtn[i][j]->SetImage(keyImg[i][j]);
                //keyBtn[i][j]->SetImageOver(keyImgOver[i][j]);
                //keyBtn[i][j]->SetSoundOver(keySoundOver);
                //keyBtn[i][j]->SetSoundClick(keySoundClick);
                //keyBtn[i][j]->SetTrigger(trigA);
                keyBtn[i][j]->SetLabel(keyTxt[i][j]);
                //keyBtn[i][j]->SetPosition((j*42+21*i+40)+eurocheck, i*42+120);//SetPosition(j*42+21*i+40, i*42+80);
                //keyBtn[i][j]->SetEffectGrow();
                this->Append(keyBtn[i][j]);
            }
        }
    }
}

/**
 * Destructor for the GuiKeyboard class.
 */
GuiKeyboard::~GuiKeyboard()
{
    delete kbText;
    delete keyTextbox;
    delete keyTextboxImg;
    delete keyCapsText;
    delete keyCapsImg;
    delete keyCapsOverImg;
    delete keyCaps;
    delete keyShiftText;
    delete keyShiftImg;
    delete keyShiftOverImg;
    delete keyShift;
    if (keyAlt)
    {
        delete keyAlt;
    }
    if (keyAlt2)
    {
        delete keyAlt2;
    }
    delete keyBackText;
    delete keyBackImg;
    delete keyBackOverImg;
    delete keyBack;
    delete keySpaceImg;
    delete keySpaceOverImg;
    delete keySpace;
    delete key;
    delete keyOver;
    delete keyMedium;
    delete keyMediumOver;
    delete keyLarge;
    delete keyLargeOver;
    delete trigA;
    delete trigB;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (keys[i][j].ch != '\0')
            {
                delete keyImg[i][j];
                delete keyImgOver[i][j];
                delete keyTxt[i][j];
                delete keyBtn[i][j];
            }
        }
    }
}

void GuiKeyboard::Update(GuiTrigger * t)
{
    LOCK( this );
    if (_elements.size() == 0 || (state == STATE_DISABLED && parentElement)) return;

    for (u8 i = 0; i < _elements.size(); i++)
    {
        try
        {
            _elements.at(i)->Update(t);
        }
        catch (const std::exception& e)
        {
        }
    }

    bool changedShiftKey = false;

    if (keySpace->GetState() == STATE_CLICKED)
    {
        if (strlen(kbtextstr) < kbtextmaxlen - 1) // -1 --> kbtextmaxlen means with terminating '\0'
        {
            kbtextstr[strlen(kbtextstr)] = ' ';
            kbText->SetText(kbtextstr);
        }
        keySpace->SetState(STATE_SELECTED, t->chan);
    }
    else if (keyBack->GetState() == STATE_CLICKED)
    {
        if (strlen(kbtextstr) > (m))
        {
            kbtextstr[strlen(kbtextstr) - 1] = 0;
            kbText->SetText(kbtextstr);
        }
        keyBack->SetState(STATE_SELECTED, t->chan);
    }
    else if (keyClear->GetState() == STATE_CLICKED)
    {
        while (strlen(kbtextstr) > (m))
        {
            kbtextstr[strlen(kbtextstr) - 1] = 0;
            kbText->SetText(kbtextstr);
        }
        keyClear->SetState(STATE_SELECTED, t->chan);
    }
    else if (keyShift->GetState() == STATE_CLICKED)
    {
        changedShiftKey = true;
        shift ^= 1;
        if (alt) alt ^= 1;
        if (alt2) alt2 ^= 1;
        keyShift->SetState(STATE_SELECTED, t->chan);
    }
    else if (keyAlt->GetState() == STATE_CLICKED)
    {
        changedShiftKey = true;
        alt ^= 1;
        if (shift) shift ^= 1;
        if (alt2) alt2 ^= 1;
        keyAlt->SetState(STATE_SELECTED, t->chan);
    }
    else if (keyAlt2->GetState() == STATE_CLICKED)
    {
        changedShiftKey = true;
        alt2 ^= 1;
        if (shift) shift ^= 1;
        if (alt) alt ^= 1;
        keyAlt2->SetState(STATE_SELECTED, t->chan);
    }
    else if (keyCaps->GetState() == STATE_CLICKED)
    {
        changedShiftKey = true;
        caps ^= 1;
        keyCaps->SetState(STATE_SELECTED, t->chan);
    }

    bool update = false;

    char txt[2] = { 0, 0 };

    do
    {
        update = false;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if (keys[i][j].ch != '\0')
                {
                    if (shift || caps)
                        txt[0] = keys[i][j].chShift;
                    else if (alt)
                        txt[0] = keys[i][j].chalt;
                    else if (alt2)
                        txt[0] = keys[i][j].chalt2;
                    else txt[0] = keys[i][j].ch;

                    if (changedShiftKey) // change text only if needed
                    keyTxt[i][j]->SetText(txt);

                    if (keyBtn[i][j]->GetState() == STATE_CLICKED)
                    {
                        if (strlen(kbtextstr) < kbtextmaxlen - 1) // -1 --> kbtextmaxlen means with term. '\0'
                        {
                            kbtextstr[strlen(kbtextstr)] = txt[0];
                            kbText->SetText(kbtextstr);
                        }
                        keyBtn[i][j]->SetState(STATE_SELECTED, t->chan);

                        if (shift || alt || alt2)
                        {
                            if (shift) shift ^= 1;
                            if (alt) alt ^= 1;
                            if (alt2) alt2 ^= 1;
                            update = true;
                            changedShiftKey = true;
                        }
                    }
                }
            }
        }
    } while (update);

    kbText->SetPosition(0, 53);

    this->ToggleFocus(t);

    if (focus) // only send actions to this window if it's in focus
    {
        // pad/joystick navigation
        if (t->Right())
            this->MoveSelectionHor(1);
        else if (t->Left())
            this->MoveSelectionHor(-1);
        else if (t->Down())
            this->MoveSelectionVert(1);
        else if (t->Up()) this->MoveSelectionVert(-1);
    }
}
