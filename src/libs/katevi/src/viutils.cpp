#include "viutils.h"

#include <Qt>

using namespace KateVi;

bool ViUtils::isModifier(int p_keyCode)
{
    return p_keyCode == Qt::Key_Shift
           || p_keyCode == Qt::Key_Control
           || p_keyCode == Qt::Key_Alt
           || p_keyCode == Qt::Key_Meta;
}

bool ViUtils::isRegister(QChar p_char)
{
    return (p_char >= QLatin1Char('0') && p_char <= QLatin1Char('9'))
           || (p_char >= QLatin1Char('a') && p_char <= QLatin1Char('z'))
           || p_char == QLatin1Char('_')
           || p_char == QLatin1Char('+')
           || p_char == QLatin1Char('*')
           || p_char == QLatin1Char('#')
           || p_char == QLatin1Char('^');
}

// Just judge MacOS for now, everything else is considered to be same.
bool ViUtils::isControlModifier(int p_modifiers)
{
#if defined(Q_OS_MACOS) || defined(Q_OS_MAC)
    return p_modifiers == Qt::MetaModifier;
#else
    return p_modifiers == Qt::ControlModifier;
#endif
}
