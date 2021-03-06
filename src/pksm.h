struct pkx
{
    int species;
    int form;
};
enum Generation
{
    GEN_FOUR,
    GEN_FIVE,
    GEN_SIX,
    GEN_SEVEN,
    GEN_LGPE,
    GEN_EIGHT,
    GEN_THREE
};
struct directory
{
    int count;
    char** files;
};
enum PKX_Field
{
    OT_NAME,
    TID,
    SID,
    SHINY,
    LANGUAGE,
    MET_LOCATION,
    MOVE,
    BALL,
    LEVEL,
    GENDER,
    ABILITY,
    IV_HP,
    IV_ATK,
    IV_DEF,
    IV_SPATK,
    IV_SPDEF,
    IV_SPEED,
    NICKNAME,
    ITEM,
    POKERUS,
    EGG_DAY,
    EGG_MONTH,
    EGG_YEAR,
    MET_DAY,
    MET_MONTH,
    MET_YEAR,
    FORM,
    EV_HP,
    EV_ATK,
    EV_DEF,
    EV_SPATK,
    EV_SPDEF,
    EV_SPEED,
    SPECIES,
    PID,
    NATURE,
    FATEFUL,
    PP,
    PP_UPS,
    EGG,
    NICKNAMED,
    EGG_LOCATION,
    MET_LEVEL,
    OT_GENDER,
    ORIGINAL_GAME
};
enum SAV_Field
{
    SAV_OT_NAME,
    SAV_TID,
    SAV_SID,
    SAV_GENDER,
    SAV_COUNTRY,
    SAV_SUBREGION,
    SAV_REGION,
    SAV_LANGUAGE,
    SAV_MONEY,
    SAV_BP,
    SAV_HOURS,
    SAV_MINUTES,
    SAV_SECONDS,
    SAV_ITEM
};
enum SAV_MaxField
{
    MAX_SLOTS,
    MAX_BOXES,
    MAX_WONDER_CARDS,
    MAX_FORM,
    MAX_IN_POUCH
};
enum SAV_CheckValue
{
    SAV_VALUE_SPECIES,
    SAV_VALUE_MOVE,
    SAV_VALUE_ITEM,
    SAV_VALUE_ABILITY,
    SAV_VALUE_BALL
};
enum Pouch
{
    NormalItem,
    KeyItem,
    TM,
    Mail,
    Medicine,
    Berry,
    Ball,
    Battle,
    Candy,
    ZCrystals
};

int gui_choice(char* message);
void gui_warn(char* warning);
int gui_menu_6x5(char* question, int options, char** labels, struct pkx* pokemon, enum Generation generation);
int gui_menu_20x2(char* question, int options, char** labels);
void gui_keyboard(char* out, char* hint, int maxChars);
void gui_numpad(unsigned int* out, char* hint, int maxDigits);
int gui_boxes(int* fromStorage, int* box, int* slot, int doCrypt);
int sav_sbo();
int sav_gbo();
void sav_box_decrypt();
void sav_box_encrypt();
void sav_get_pkx(char* data, int box, int slot);
void sav_inject_pkx(char* data, enum Generation type, int box, int slot, int doTradeEdits);
int sav_get_value(enum SAV_Field field, ...);
int sav_get_max(enum SAV_MaxField field, ...);
char* sav_get_string(unsigned int offset, unsigned int codepoints);
void sav_set_string(char* string, unsigned int offset, unsigned int codepoints);
int sav_check_value(enum SAV_CheckValue field, int value);
void party_get_pkx(char* data, int slot);
void party_inject_pkx(char* data, enum Generation type, int slot);
void bank_inject_pkx(char* data, enum Generation type, int box, int slot);
void sav_inject_wcx(char* data, enum Generation type, int slot, int alternateFormat);
int sav_wcx_free_slot();
char* bank_get_pkx(enum Generation* type, int box, int slot);
int bank_get_size();
void bank_select();
void pkx_decrypt(char* data, enum Generation type, int isParty);
void pkx_encrypt(char* data, enum Generation type, int isParty);
int pkx_box_size(enum Generation gen);
int pkx_party_size(enum Generation gen);
void pkx_generate(char* data, int species);
int pkx_is_valid(char* data, enum Generation gen);
void pkx_set_value(char* data, enum Generation gen, enum PKX_Field field, ...);
unsigned int pkx_get_value(char* data, enum Generation gen, enum PKX_Field field, ...);
char* current_directory();
struct directory* read_directory(char* dir);
void delete_directory(struct directory* dir);
char* cfg_default_ot();
unsigned short cfg_default_tid();
unsigned short cfg_default_sid();
int cfg_default_day();
int cfg_default_month();
int cfg_default_year();
char* net_ip();
int net_tcp_recv(char* buffer, int size, int* received);
int net_tcp_send(char* ip, int port, char* buffer, int size);
int net_udp_recv(char* buffer, int size, int* received);
char* i18n_species(int species);
char* utf16_to_utf8(char* data);
char* utf8_to_utf16(char* data);
int fetch_web_content(char** out, int* outSize, char* url);
void base64_decode(unsigned char** out, int* outSize, char* data, int size);
void base64_encode(char** out, int* outSize, unsigned char* data, int size);
