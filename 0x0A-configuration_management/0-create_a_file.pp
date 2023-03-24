#we will create a file in the temp directo#ry that will be maintained even when
changes are made

file = { '/tmp/school':
	ensure	=> present,
	mode	=> 0744
	owner	=> 'www-data'
	group	=> 'www-data'
	content	=> 'I love Puppet'
}
