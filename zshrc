# If you come from bash you might have to change your $PATH.
# export PATH=$HOME/bin:$HOME/.local/bin:/usr/local/bin:$PATH

# Path to your Oh My Zsh installation.
export ZSH="$HOME/.oh-my-zsh"

# Set name of the theme to load
ZSH_THEME="blinks"

# Uncomment one of the following lines to change the auto-update behavior
# zstyle ':omz:update' mode disabled
# zstyle ':omz:update' mode auto
# zstyle ':omz:update' mode reminder

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Which plugins would you like to load?
# plugins=(git)

source $ZSH/oh-my-zsh.sh

# User configuration

# export MANPATH="/usr/local/man:$MANPATH"
# export LANG=en_US.UTF-8

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='nvim'
# fi

# Compilation flags
# export ARCHFLAGS="-arch $(uname -m)"

# Personal aliases
alias val="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes"
alias valp="valgrind --leak-check=full --trace-children=yes --track-fds=yes --show-leak-kinds=all --track-origins=yes"
alias valog="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind_report.log"
alias valpog="valgrind --leak-check=full --trace-children=yes --track-fds=yes --show-leak-kinds=all --track-origins=yes --log-file=valgrind_report.log"
alias tor="~/bin/Browser/start-tor-browser"
# alias nvim="$HOME/AppImages/nvim.appimage"
alias ccf="cc -Wall -Werror -Wextra"
alias ccg="ccf -g"
alias hama="/home/pedro/bin/hamachi-toggle.sh"
alias code="codium"
alias norme="clear && norminette"
alias nconfig='(cd "$HOME/.config/nvim" && nvim .)'
alias fuck="sudo fsck -fy"
alias mountHDD="sudo cryptsetup open --key-file /var/usrlocal/backup.key 8129ef3a-3fad-4849-bd22-b349fb3bc002 backup_crypt"
alias vold="pactl set-sink-volume @DEFAULT_SINK@ -1%"
alias volu="pactl set-sink-volume @DEFAULT_SINK@ +1%"
alias mute="pactl set-sink-volume @DEFAULT_SINK@ toggle"

alias batper="cat /sys/class/power_supply/BAT*/capacity"

export PATH="$HOME/.local/bin:$PATH"
export PATH="$HOME/bin:$PATH"
export PATH="$PATH:/var/home/pedro/AppImages/"

#$HOME/bin subdirectories
alias ase="$HOME/bin/Aseprite/build/bin/aseprite"
alias scrcpy="$HOME/bin/scrcpy/scrcpy"
alias adb="$HOME/bin/scrcpy/adb"
alias lmms="$HOME/bin/lmms/build/lmms"
down-ytpl() {
    if [ -z "$1" ]; then
        echo "Usage: down-ytpl <YouTube playlist URL>"
        return 1
    fi
    ~/.local/bin/yt-dlp -x --audio-format mp3 \
        --cookies-from-browser vivaldi \
        --user-agent "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/116.0.0.0 Safari/537.36" \
        "$1"
}

ecode() {
  codium "$@"
  if [ $? -eq 0 ]; then
    exit
  fi
}

cast() {
    if [ "$1" = "list" ]; then
        v4l2-ctl --list-devices
        return
    fi

    if [ -z "$1" ]; then
        echo "Usage: cast [video_device]"
        echo "Example: cast video2"
        echo "Or:      cast list"
        return 1
    fi

    local dev="/dev/${1}"
    if [ ! -e "$dev" ]; then
        echo "❌ Device $dev not found!"
        return 1
    fi

    mpv --profile=low-latency --no-cache --untimed --fs "$dev"
}

debug() {
    cc -g -Wall -Werror -Wextra "$@" && gdb ./a.out
}

convertall() {
  if (( $# != 2 )); then
    echo "Usage: convertall <src_glob> <dest_glob>"
    echo "Example: convertall \"folder1/*.png\" \"folder2/*.xpm\""
    return 1
  fi

  local src_glob=$1
  local dest_glob=$2
  local dest_dir=${dest_glob%/*}
  local dest_ext=${dest_glob##*.}
  local files=( ${(~)src_glob} )

  if (( ${#files} == 0 )); then
    echo "No files match: $src_glob"
    return 1
  fi

  convert mogrify -format $dest_ext -path $dest_dir "${files[@]}"
}

export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"
