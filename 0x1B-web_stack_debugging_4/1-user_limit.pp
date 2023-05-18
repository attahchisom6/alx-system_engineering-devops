# a pupper to increase the limit of system open files

exec {'Good! the sky is not the limit':
	provider => shell,
	command => 'sed -i s/holberton/"# holberton"/ /etc/security/limits.conf'
}
