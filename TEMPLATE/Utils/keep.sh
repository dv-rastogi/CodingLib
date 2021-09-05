#!/bin/bash
# Removes old revisions of snaps
# CLOSE ALL SNAPS BEFORE RUNNING THIS
set -eu
snap list --all | awk '/disabled/{print $1, $3}' |
    while read snapname revision; do
        snap remove "$snapname" --revision="$revision"
    done

echo "apt autoremove";
apt autoremove;

echo "Cleaning apt cache";
apt-get clean;

echo "Journal logs";
journalctl --disk-usage;
journalctl --vacuum-size=100M;

echo "Purging pip cache";
pip cache purge;

# echo "enabling colors";
# sudo xset led 3;

# Todo for space
# 1. Clear journal
# 2. Vscode Reset intellisense database
# 3. Vscode Clear Editor History
# 4. Default stack size: ulimit -s 8192 (Current 8192 << 1)
