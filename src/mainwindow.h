#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QUrl>

/* gestione variabile self */
#include "self_class.h"

#include <QAudioProbe>
#include <QAudioRecorder>
#include <QDir>
#include <QFileDialog>
#include <QMediaRecorder>
#include <QStandardPaths>
#include <QDebug>
#include <iostream>
#include <QComboBox>
#include <QMediaPlayer>

#include "windows/updatecheck.h"

/*TESTING*/
#include "touch/tabletcanvas.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class AudioRecorder; }
class QAudioRecorder;
class QAudioProbe;
class QAudioBuffer;

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, TabletCanvas *canvas = nullptr);
    ~MainWindow();

    /* gestione variabile self */
    SelfClass *self;
    Ui::MainWindow *ui;

    QAudioRecorder *m_audioRecorder = new QAudioRecorder(this);
    QAudioProbe *m_probe = nullptr;
    bool m_outputLocationSet = false;

    /* gestione della riproduzione dell'audio */
    QMediaPlayer *player;

    TabletCanvas *m_canvas;

    /* le due funzioni gestiscono il cambio di inserimento */
    void methodwrite();
    void methodpen();

    bool typetemp = false;

    updatecheck *checkupdate;

    void setFile(int, char **);

    void update_image();

public slots:

    /* la funzione serve anche per eliminare l'audio del copybook */
    void on_listWidgetSX_itemDoubleClicked(QListWidgetItem *item);

    void on_actioncompress_video_triggered();

    /* call by savefrom */
    void on_actionSave_File_triggered();

private slots:
    /* registrazione dell'audio */
    bool setOutputLocation();
    void togglePause();

    void on_actionNew_File_triggered();
    void closeEvent (QCloseEvent *event);


    /* richiamata quando viene modificato qualcosa del testo */
    void on_textEdit_textChanged();

    void on_actionOpen_triggered(char *nomeFile = nullptr);



    void on_textEdit_selectionChanged();

    void on_actionCreate_new_copybook_triggered();

    void on_startrecording_triggered();

    //void on_stoprecordingbotton_triggered();
    void on_pauserecordingbotton_triggered();

    /* funzione che gestisce l'aggiornamento della status bar */
    void updateProgress(qint64 duration);

    /* funzione che gestisce la visualizzazione di un errore per la registrazione del video */
    void displayErrorMessage();

    //void on_startriascolto_clicked();

    void on_stopriascolto_clicked();

    /* riascolto audio */
    /* funzione che gestisce l'inserimento del testo formattato correttamente */
    void riascoltoaudioprogressivo(qint64 position);
    void on_actionListen_current_audio_triggered();

    void on_startriascoltobotton_clicked();

    void on_boldbotton_clicked();

    void on_inserttablebotton_clicked();

    void on_insertimagebotton_clicked();

    void on_listbotton_clicked();

    void on_actionDelete_copybook_triggered();


    /* funzioni per gestire il click sull'item della lista */
    void deleteaudio_f();
    void deletecopybook_f();
    void audiototext_f();
    void renamefile_f();
    void compressvideo_f();



    /* funzione che gestisce la fine del riascolto dell'audio */
    void cambiostatoplayer(QMediaPlayer::State);

    void on_actionQuality_setting_triggered();

    void on_stoprecordingbotton_triggered();

    void on_actionDelete_audio_triggered();


    void on_volumeSlider_actionTriggered(int action);

    void on_spinBox_fontsize_valueChanged(const QString &arg1);

    void on_fontComboBox_fonttipo_currentFontChanged(const QFont &f);

    void on_actionPrint_triggered();


    void on_audioSlider_valueChanged(int value);

    void on_volumeSlider_valueChanged(int value);

    void on_actionRedo_triggered();

    void on_actionCut_triggered();

    void on_actionSelect_all_triggered();

    void on_actionPaste_triggered();

    void on_actionCopy_triggered();

    void on_actionpen_triggered();

    void on_actionrubber_triggered();

    void on_actionblack_triggered();

    void on_actionwhite_triggered();

    void on_actionyellow_triggered();

    void on_actionred_triggered();

    void on_actionselezionetext_triggered();

    void on_actionSave_As_triggered();

    void on_actiontoppf_triggered();

    void on_actionSource_code_triggered();

    void on_insertimagebotton_triggered(QAction *arg1);

    void on_actionCheck_update_triggered();

    void on_actioninsertImage_triggered();

private:
    /* gestione dell'audio */
    void clearAudioLevels();

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;
    bool event(QEvent *event) override;

};
#endif // MAINWINDOW_H
