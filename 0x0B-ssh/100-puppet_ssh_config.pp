#making a puppet file to configure my host file

include stdlib

file_line { 'Turn off passwd auth':
	ensure	=> present,
	path	=> '/etc/ssh/ssh_config',
	line	=  '	passwordAuthentication no',
	replace	=> true,
}

file_line { 'Declare Identity file':
	ensure	=> present,
	path	=> '/etc/ssh/ssh_config',
	line	=> '	IdentityFile ~/.ssh/school'
	replace	=> true,
}
