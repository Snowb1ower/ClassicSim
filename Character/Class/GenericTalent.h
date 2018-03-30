#ifndef GENERICTALENT_H
#define GENERICTALENT_H

#include "Talent.h"

class TalentTree;

class GenericTalent: public Talent {
    Q_OBJECT
public:
    GenericTalent(Character *pchar,
                  TalentTree *tree,
                  const QString &name,
                  const QString &position,
                  const QString &icon,
                  const int max_points,
                  const QString &rank_description,
                  const int base_val,
                  const int increment,
                  bool use_increment);
    virtual ~GenericTalent();

    virtual void apply_rank_effect() override;
    virtual void remove_rank_effect() override;
};

#endif // GENERICTALENT_H