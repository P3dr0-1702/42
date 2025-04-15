# Lines configured by zsh-newuser-install
HISTFILE=~/.histfile
HISTSIZE=100000
SAVEHIST=1000
bindkey -e
# End of lines configured by zsh-newuser-install
# The following lines were added by compinstall
zstyle :compinstall filename '/home/pfreire-/.zshrc'


# unset path
autoload -Uz compinit
compinit
# End of lines added by compinstall

alias francinette=/home/pfreire-/francinette/tester.sh
alias code="flatpak run com.visualstudio.code"
alias val="valgrind --leak-check=full --show-leak-kinds=all"
alias paco=/home/pfreire-/francinette/tester.sh
alias ccf="cc -Wall -Werror -Wextra"
alias ccg="ccf -g"
