# Writernote

<table border="0px" ><tr><td width = 600px>


</td><td>

</td></tr></table>


<table>
<tr>
<td>
## Linux

<img src="readme/linux-example.png" width=100% title="writernote Screenshot on Linux"/>
</td>
</tr>
</table>

## Experimental Features:
- Import images

## To do
- Introduce touch support
- Convert audio to text

## Installing
  - Linux: 
    
    Install stable version [from snapd]
    ```bash
    sudo snap install writernote
    sudo snap connect writernote:audio-record
    ```

    Install unstable version [last]
    With multipass you can specify how many thread, ram, and disk, for the virtual machine for compilation.
    Personaly i use 20 thread, 24G ram, and 100G of disk.

    ```bash
    sudo snap install multipass 
    sudo snap install snapcraft --classic
    git clone https://github.com/giacomogroppi/writernote-qt.git
    cd writernote-qt
    multipass launch --name snapcraft-writernote --cpus 20 --mem 24G --disk 100G
    snapcraft

    sudo snap install writernote*.snap --devmode --dangerous
    sudo snap connect writernote:audio-record
    ```

  - Windows:
    coming soon

## Compiling
  - Linux:
    dependence:
      it's raccomend to download qt creator, with all the component, from the official website.
      in case you can install all the dependence by install all the package from build-packages and the stage-packages in snapcraft.yaml [writernote]

    compily:
      ```bash
        mkdir build
        qmake writernote.pro
        make -j $nproc
      ```
  

## File format

The _.writer format is a compressed archive, in which a file `` indice.xml '' can be found, in which all the notebooks and all the audio are saved, whether they are recorded, or whether they are imported by the application.

When the file is open, only the indice.xml and the file of the copybook is loaded.


## Development
The application is entirely developed by Giacomo Groppi.
For developing new features, write a Ticket, so others know what you are doing. For development create a fork, and use the test as base. Create a Pull request for each fix. Do not create big pull requests, as long as you don't break anything features also can be merged, even if they are not 100% finished.. To report a problem send an email to the same address [possible with the error log and/or with a photo].

See [GitHub:writernote](http://github.com/giacomogroppi/writernote-qt) for current development.