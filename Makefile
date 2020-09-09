bucket-list-prioritized.md: FORCE prioritize_bucket_list/prioritize_bucket_list
	prioritize_bucket_list/prioritize_bucket_list
prioritize_bucket_list/prioritize_bucket_list: FORCE
	echo Entering directory \`prioritize_bucket_list\'
	cd prioritize_bucket_list && coddle
	echo Leaving directory \`prioritize_bucket_list\'
FORCE:
