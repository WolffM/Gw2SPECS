#include "configurator.h"
#include "ui_configurator.h"
#include "settings.h"
#include "mainwindow.h"
#include <global.h>

using namespace GW2;

Configurator::Configurator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Configurator)
{
    ui->setupUi(this);

    // hide not used settings:
    ui->checkBoxCDamage->setVisible(false);
    ui->checkBoxCDPS->setVisible(false);
    ui->checkBoxCPerDmg->setVisible(false);
    ui->checkBoxActivity->setVisible(false);

    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

    // Set version
    ui->labelVersion->setText(Settings::s_Product);

    Settings::ReadSettings(ui->checkBoxToolbar);
    Settings::ReadSettings(ui->checkBoxDetails);
    Settings::ReadSettings(ui->checkBoxExtraDetails);
    Settings::ReadSettings(ui->checkBoxOpacity);
    Settings::ReadSettings(ui->checkBoxOBS);
    Settings::ReadSettings(ui->comboBoxLanguage);

    Settings::ReadSettings(ui->checkBoxProfColors);
    Settings::ReadSettings(ui->checkBoxName);
    Settings::ReadSettings(ui->checkBoxDamage);
    Settings::ReadSettings(ui->checkBoxDPS);
    Settings::ReadSettings(ui->checkBoxCDamage);
    Settings::ReadSettings(ui->checkBoxCPerDmg);
    Settings::ReadSettings(ui->checkBoxCDPS);
    Settings::ReadSettings(ui->checkBox5sDPS);
    Settings::ReadSettings(ui->checkBoxPosition);
    Settings::ReadSettings(ui->checkBoxPerDmg);
    Settings::ReadSettings(ui->checkBoxActivity);

    Settings::ReadSettings(ui->checkBoxGraphShow);
    Settings::ReadSettings(ui->checkBoxGraphRealDPS);
    Settings::ReadSettings(ui->checkBoxGraph5sDPS);
    Settings::ReadSettings(ui->checkBoxGraphAvgDPS);
    Settings::ReadSettings(ui->checkBoxGraphAvgCDPS);
    Settings::ReadSettings(ui->checkBoxGraphAvgGroupDPS);

    Settings::ReadSettings(ui->comboBoxScreenshots);
    Settings::ReadSettings(ui->comboBoxUpdates);
    Settings::ReadSettings(ui->comboBoxSecondsInCombat);
    Settings::ReadSettings(ui->comboBoxConsideredLines);

    Settings::ReadSettings(ui->checkBoxShortcutDisable);
    Settings::ReadSettings(ui->seqEditCombatMode);
    Settings::ReadSettings(ui->seqEditGlobalReset);
    Settings::ReadSettings(ui->seqEditReset);
    Settings::ReadSettings(ui->seqEditSave);
    Settings::ReadSettings(ui->seqEditOpacity);
}

Configurator::~Configurator()
{
    Settings::WriteSettings(ui->checkBoxToolbar);
    Settings::WriteSettings(ui->checkBoxDetails);
    Settings::WriteSettings(ui->checkBoxExtraDetails);
    Settings::WriteSettings(ui->checkBoxOpacity);
    Settings::WriteSettings(ui->checkBoxOBS);
    Settings::WriteSettings(ui->comboBoxLanguage);

    Settings::WriteSettings(ui->checkBoxProfColors);
    Settings::WriteSettings(ui->checkBoxName);
    Settings::WriteSettings(ui->checkBoxDamage);
    Settings::WriteSettings(ui->checkBoxDPS);
    Settings::WriteSettings(ui->checkBoxCDamage);
    Settings::WriteSettings(ui->checkBoxCPerDmg);
    Settings::WriteSettings(ui->checkBoxCDPS);
    Settings::WriteSettings(ui->checkBox5sDPS);
    Settings::WriteSettings(ui->checkBoxPosition);
    Settings::WriteSettings(ui->checkBoxPerDmg);
    Settings::WriteSettings(ui->checkBoxActivity);

    Settings::WriteSettings(ui->checkBoxGraphShow);
    Settings::WriteSettings(ui->checkBoxGraphRealDPS);
    Settings::WriteSettings(ui->checkBoxGraph5sDPS);
    Settings::WriteSettings(ui->checkBoxGraphAvgDPS);
    Settings::WriteSettings(ui->checkBoxGraphAvgCDPS);
    Settings::WriteSettings(ui->checkBoxGraphAvgGroupDPS);

    Settings::WriteSettings(ui->comboBoxScreenshots);
    Settings::WriteSettings(ui->comboBoxUpdates);
    Settings::WriteSettings(ui->comboBoxSecondsInCombat);
    Settings::WriteSettings(ui->comboBoxConsideredLines);

    Settings::WriteSettings(ui->checkBoxShortcutDisable);
    Settings::WriteSettings(ui->seqEditCombatMode);
    Settings::WriteSettings(ui->seqEditGlobalReset);
    Settings::WriteSettings(ui->seqEditReset);
    Settings::WriteSettings(ui->seqEditSave);
    Settings::WriteSettings(ui->seqEditOpacity);

    delete ui;
}

void Configurator::RestoreDefaults()
{
    ui->checkBoxToolbar->setChecked(true);
    ui->checkBoxDetails->setChecked(false);
    ui->checkBoxExtraDetails->setChecked(false);
    ui->checkBoxOpacity->setChecked(false);
    ui->checkBoxOBS->setChecked(false);
    ui->comboBoxLanguage->setCurrentIndex(0);

    ui->checkBoxProfColors->setChecked(false);
    ui->checkBoxName->setChecked(true);
    ui->checkBoxDamage->setChecked(true);
    ui->checkBoxDPS->setChecked(true);
    ui->checkBox5sDPS->setChecked(false);
    ui->checkBoxPerDmg->setChecked(false);
    ui->checkBoxPosition->setChecked(true);

    ui->checkBoxActivity->setChecked(false);
    ui->checkBoxCDamage->setChecked(false);
    ui->checkBoxCPerDmg->setChecked(false);
    ui->checkBoxCDPS->setChecked(false);

    ui->checkBoxGraphShow->setChecked(true);
    ui->checkBoxGraphRealDPS->setChecked(false);
    ui->checkBoxGraph5sDPS->setChecked(true);
    ui->checkBoxGraphAvgDPS->setChecked(true);
    ui->checkBoxGraphAvgCDPS->setChecked(true);
    ui->checkBoxGraphAvgGroupDPS->setChecked(true);

    ui->comboBoxScreenshots->setCurrentIndex(0);
    ui->comboBoxUpdates->setCurrentIndex(0);
    ui->comboBoxSecondsInCombat->setCurrentIndex(0);
    ui->comboBoxConsideredLines->setCurrentIndex(3);

    // Only needed and set when using windows.
    #ifdef Q_OS_WIN
    ui->checkBoxShortcutDisable->setChecked(true);
    ui->seqEditCombatMode->setKeySequence(QKeySequence(Settings::shortcut_combatmode));
    ui->seqEditGlobalReset->setKeySequence(QKeySequence(Settings::shortcut_globalreset));
    ui->seqEditReset->setKeySequence(QKeySequence(Settings::shortcut_reset));
    ui->seqEditSave->setKeySequence(QKeySequence(Settings::shortcut_savelog));
    ui->seqEditOpacity->setKeySequence(QKeySequence(Settings::shortcut_opacity));

    on_seqEditCombatMode_editingFinished();
    on_seqEditGlobalReset_editingFinished();
    on_seqEditReset_editingFinished();
    on_seqEditSave_editingFinished();
    on_seqEditOpacity_editingFinished();
    #endif
}

// Give movement access to Configurator
void Configurator::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}

// Give movement access to Configurator
void Configurator::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
}

// This functions only need to be loaded when the OS is Windows. Otherwise there will be errors since the
// Key-Capture is a Windows API function.

#ifdef Q_OS_WIN
void GW2::Configurator::on_seqEditCombatMode_editingFinished()
{
    // setting default if empty
    if(ui->seqEditCombatMode->keySequence().toString() == ""){
        ui->seqEditCombatMode->setKeySequence(QKeySequence(Settings::shortcut_combatmode));
    }

    // getting string from sequenceedit and converting it to array
    QString combatmodeValPre = ui->seqEditCombatMode->keySequence().toString().toLower();
    QString combatmodeVal = combatmodeValPre.left(combatmodeValPre.indexOf(","));
    QStringList combatmodeValArray = combatmodeVal.split('+');

    // find keycode
    QString combatmodeKeycodeString = combatmodeValArray[combatmodeValArray.length()-1];
    char combatmodeKeycodeChar = combatmodeKeycodeString.data()->toLatin1();
    combatmodeKeycode = VkKeyScan(combatmodeKeycodeChar);

    // find modificator (ctrl:1; alt:2; shift:4)
    combatmodeMod=0;
    for (int i=0; i<combatmodeValArray.length(); i++)
    {
        QString tmpstring = combatmodeValArray[i];
        if (tmpstring.indexOf("ctrl")>=0) combatmodeMod+=1;
        if (tmpstring.indexOf("alt")>=0) combatmodeMod+=2;
        if (tmpstring.indexOf("shift")>=0) combatmodeMod+=4;
    }
    combatModeToggleState = 0;
}

void GW2::Configurator::on_seqEditReset_editingFinished()
{
    // setting default if empty
    if(ui->seqEditReset->keySequence().toString() == ""){
        ui->seqEditReset->setKeySequence(QKeySequence(Settings::shortcut_reset));
    }

    // getting string from sequenceedit and converting it to array
    QString resetValPre = ui->seqEditReset->keySequence().toString().toLower();
    QString resetVal = resetValPre.left(resetValPre.indexOf(","));
    QStringList resetValArray = resetVal.split('+');

    // find keycode
    QString resetKeycodeString = resetValArray[resetValArray.length()-1];
    char resetKeycodeChar = resetKeycodeString.data()->toLatin1();
    resetKeycode = VkKeyScan(resetKeycodeChar);

    // find modificator (ctrl:1; alt:2; shift:4)
    resetMod=0;
    for (int i=0; i<resetValArray.length(); i++)
    {
        QString tmpstring = resetValArray[i];
        if (tmpstring.indexOf("ctrl")>=0) resetMod+=1;
        if (tmpstring.indexOf("alt")>=0) resetMod+=2;
        if (tmpstring.indexOf("shift")>=0) resetMod+=4;
    }
}

void GW2::Configurator::on_seqEditGlobalReset_editingFinished()
{
    // setting default if empty
    if(ui->seqEditGlobalReset->keySequence().toString() == ""){
        ui->seqEditGlobalReset->setKeySequence(QKeySequence(Settings::shortcut_globalreset));
    }

    // getting string from sequenceedit and converting it to array
    QString globalresetValPre = ui->seqEditGlobalReset->keySequence().toString().toLower();
    QString globalresetVal = globalresetValPre.left(globalresetValPre.indexOf(","));
    QStringList globalresetValArray = globalresetVal.split('+');

    // find keycode
    QString globalresetKeycodeString = globalresetValArray[globalresetValArray.length()-1];
    char globalresetKeycodeChar = globalresetKeycodeString.data()->toLatin1();
    globalresetKeycode = VkKeyScan(globalresetKeycodeChar);

    // find modificator (ctrl:1; alt:2; shift:4)
    globalresetMod=0;
    for (int i=0; i<globalresetValArray.length(); i++)
    {
        QString tmpstring = globalresetValArray[i];
        if (tmpstring.indexOf("ctrl")>=0) globalresetMod+=1;
        if (tmpstring.indexOf("alt")>=0) globalresetMod+=2;
        if (tmpstring.indexOf("shift")>=0) globalresetMod+=4;
    }
}

void GW2::Configurator::on_seqEditSave_editingFinished()
{
    // setting default if empty
    if(ui->seqEditSave->keySequence().toString() == ""){
        ui->seqEditSave->setKeySequence(QKeySequence(Settings::shortcut_savelog));
    }

    // getting string from sequenceedit and converting it to array
    QString savelogValPre = ui->seqEditSave->keySequence().toString().toLower();
    QString savelogVal = savelogValPre.left(savelogValPre.indexOf(","));
    QStringList savelogValArray = savelogVal.split('+');

    // find keycode
    QString savelogKeycodeString = savelogValArray[savelogValArray.length()-1];
    char savelogKeycodeChar = savelogKeycodeString.data()->toLatin1();
    savelogKeycode = VkKeyScan(savelogKeycodeChar);

    // find modificator (ctrl:1; alt:2; shift:4)
    savelogMod=0;
    for (int i=0; i<savelogValArray.length(); i++)
    {
        QString tmpstring = savelogValArray[i];
        if (tmpstring.indexOf("ctrl")>=0) savelogMod+=1;
        if (tmpstring.indexOf("alt")>=0) savelogMod+=2;
        if (tmpstring.indexOf("shift")>=0) savelogMod+=4;
    }
}

void GW2::Configurator::on_seqEditOpacity_editingFinished()
{
    // setting default if empty
    if(ui->seqEditOpacity->keySequence().toString() == ""){
        ui->seqEditOpacity->setKeySequence(QKeySequence(Settings::shortcut_opacity));
    }

    // getting string from sequenceedit and converting it to array
    QString opacityValPre = ui->seqEditOpacity->keySequence().toString().toLower();
    QString opacityVal = opacityValPre.left(opacityValPre.indexOf(","));
    QStringList opacityValArray = opacityVal.split('+');

    // find keycode
    QString opacityKeycodeString = opacityValArray[opacityValArray.length()-1];
    char opacityKeycodeChar = opacityKeycodeString.data()->toLatin1();
    opacityKeycode = VkKeyScan(opacityKeycodeChar);

    // find modificator (ctrl:1; alt:2; shift:4)
    opacityMod=0;
    for (int i=0; i<opacityValArray.length(); i++)
    {
        QString tmpstring = opacityValArray[i];
        if (tmpstring.indexOf("ctrl")>=0) opacityMod+=1;
        if (tmpstring.indexOf("alt")>=0) opacityMod+=2;
        if (tmpstring.indexOf("shift")>=0) opacityMod+=4;
    }
}
#endif
