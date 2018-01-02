#ifndef MECHANICS_H
#define MECHANICS_H

#include <algorithm>

class Mechanics {
public:
    Mechanics(int _tlvl, int _hit): tlvl(_tlvl), tdefense(_tlvl * 5), hit_chance(_hit) {}

    float get_yellow_miss_chance(const int) const;
    float get_1h_white_miss_chance(const int) const;
    float get_2h_white_miss_chance(const int) const;
    float get_dw_white_miss_chance(const int) const;

    float get_glancing_blow_chance(const int) const;
    float get_dodge_chance(const int) const;
    float get_parry_chance(const int) const;
    float get_block_chance(void) const;

    void set_tlvl(const int);
protected:
private:
    int tlvl;
    int tdefense;
    int hit_chance;
};

#endif // MECHANICS_H