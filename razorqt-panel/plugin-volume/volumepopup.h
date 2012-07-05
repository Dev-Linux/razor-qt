/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * Razor - a lightweight, Qt based, desktop toolset
 * http://razor-qt.org
 *
 * Copyright: 2012 Razor team
 * Authors:
 *   Johannes Zellner <webmaster@nebulon.de>
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */

#ifndef VOLUMEPOPUP_H
#define VOLUMEPOPUP_H

#include <QtGui/QWidget>

class QSlider;
class QToolButton;
class PulseAudioDevice;

class VolumePopup : public QWidget
{
    Q_OBJECT
public:
    VolumePopup(QWidget* parent = 0);
    ~VolumePopup();

    void open(QPoint pos, Qt::Corner anchor);
    void handleWheelEvent(QWheelEvent *event);

    QSlider *m_volumeSlider;
    PulseAudioDevice *device() const { return m_device; }
    void setDevice(PulseAudioDevice *device);

signals:
    void mouseEnter();
    void mouseExit();
    void volumeChanged(int value);
    void deviceChanged();

protected:
    void resizeEvent(QResizeEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

private slots:
    void launchMixer();
    void handleSliderValueChanged(int value);

private:
    void realign();

    QToolButton *m_mixerButton;
    QPoint m_pos;
    Qt::Corner m_anchor;
    PulseAudioDevice *m_device;
};

#endif // VOLUMEPOPUP_H
