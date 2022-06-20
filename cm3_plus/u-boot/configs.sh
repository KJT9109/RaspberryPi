export ARCH=arm64
echo $ARCH
export CROSS_COMPILE=aarch64-linux-gnu-
echo $CROSS_COMPILE
export PROJECT_DIR=$HOME/Workspace/RaspberryPi/cm3_plus/u-boot
CTAGS_COMMAND='ctags -R'
echo -e "$CTAGS_COMMAND $PROJECT_DIR\n"
$CTAGS_COMMAND $PROJECT_DIR 
echo -e "Config Finish"
