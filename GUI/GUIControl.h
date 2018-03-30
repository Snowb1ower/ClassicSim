#ifndef GUICONTROL_H
#define GUICONTROL_H

#include <QObject>

#include "Engine.h"
#include "Test.h"
#include "Equipment.h"
#include "Target.h"
#include "CombatRoll.h"
#include "Talents.h"
#include "Character.h"
#include "Race.h"

class GUIControl: public QObject {
    Q_OBJECT
public:
    GUIControl(QObject* parent = 0);
    ~GUIControl();

    /* Character */
    Q_PROPERTY(QString classColor READ get_class_color NOTIFY classChanged)
    Q_PROPERTY(QString className READ get_class_name NOTIFY classChanged)

    /* End of Character */

    /* Talents */
    Q_PROPERTY(int talentPointsRemaining READ get_talent_points_remaining NOTIFY talentsUpdated)
    Q_PROPERTY(QString leftTalentTreeBackground READ getLeftBackgroundImage NOTIFY classChanged)
    Q_PROPERTY(QString midTalentTreeBackground READ getMidBackgroundImage NOTIFY classChanged)
    Q_PROPERTY(QString rightTalentTreeBackground READ getRightBackgroundImage NOTIFY classChanged)

    Q_INVOKABLE QString getIcon(const QString tree_position, const QString talent_position) const;
    Q_INVOKABLE bool showPosition(const QString tree_position, const QString talent_position) const;
    Q_INVOKABLE bool showBottomArrow(const QString tree_position, const QString talent_position) const;
    Q_INVOKABLE bool showRightArrow(const QString tree_position, const QString talent_position) const;

    Q_INVOKABLE QString getBottomArrow(const QString tree_position, const QString talent_position) const;
    Q_INVOKABLE QString getRightArrow(const QString tree_position, const QString talent_position) const;
    Q_INVOKABLE bool bottomChildAvailable(const QString tree_position, const QString talent_position) const;
    Q_INVOKABLE bool bottomChildActive(const QString tree_position, const QString talent_position) const;
    Q_INVOKABLE bool rightChildAvailable(const QString tree_position, const QString talent_position) const;
    Q_INVOKABLE bool rightChildActive(const QString tree_position, const QString talent_position) const;
    Q_INVOKABLE bool isActive(const QString tree_position, const QString talent_position) const;
    Q_INVOKABLE bool isAvailable(const QString tree_position, const QString talent_position) const;
    Q_INVOKABLE bool isMaxed(const QString tree_position, const QString talent_position) const;
    Q_INVOKABLE bool hasTalentPointsRemaining() const;
    Q_INVOKABLE QString getRank(const QString tree_position, const QString talent_position) const;
    Q_INVOKABLE QString getMaxRank(const QString tree_position, const QString talent_position) const;
    Q_INVOKABLE void incrementRank(const QString tree_position, const QString talent_position);
    Q_INVOKABLE void decrementRank(const QString tree_position, const QString talent_position);
    Q_INVOKABLE QString getRequirements(const QString tree_position, const QString talent_position) const;
    Q_INVOKABLE QString getCurrentRankDescription(const QString tree_position, const QString talent_position) const;
    Q_INVOKABLE QString getNextRankDescription(const QString tree_position, const QString talent_position) const;
    Q_INVOKABLE int getTreePoints(const QString tree_position) const;
    Q_INVOKABLE QString getTreeName(const QString tree_position) const;
    Q_INVOKABLE QString getTalentName(const QString tree_position, const QString talent_position) const;
    Q_INVOKABLE void maxRank(const QString tree_position, const QString talent_position);
    Q_INVOKABLE void minRank(const QString tree_position, const QString talent_position);

    Q_INVOKABLE void clearTree(const QString tree_position);

    Q_INVOKABLE void setTalentSetup(const int talent_index);
    /* End of Talents */

Q_SIGNALS:
    void talentsUpdated();
    void classChanged();

private:
    int get_talent_points_remaining() const;
    QString get_class_color() const;
    QString get_class_name() const;

    QString getLeftBackgroundImage() const;
    QString getMidBackgroundImage() const;
    QString getRightBackgroundImage() const;

    Engine* engine;
    Equipment* equipment;
    Target* target;
    Random* random;
    CombatRoll* combat;
    QMap<QString, Character*> chars;
    QMap<QString, Race*> races;
    Character* current_char;
};

#endif // GUICONTROL_H