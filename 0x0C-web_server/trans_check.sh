#!/usr/bin/env bash
#This script will transfer file from a client side to our to the home
#dirctory of a remote server

if [ $# -lt 4]
then
	echo "Usage: 0-transfer_file PATH_TO_FILE IP USERNAME PATH_TO_SSH_KEY"
else
	scp -o StrictHostKeyChecking=no "$4" "$1" "$3"@"$2":~/
fi