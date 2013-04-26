#include "git2/blame.h"
#include "common.h"
#include "vector.h"
#include "diff.h"

struct git_blame {
	const char *path;
	git_repository *repository;
	git_blame_options options;

	git_vector hunks;
	git_vector unclaimed_hunks;

	git_blob *final_blob;
	size_t num_lines;
	int *line_index;

	git_oid current_commit;
	const git_diff_delta *current_delta;
	const git_diff_range *current_range;
	size_t current_line;
	git_blame_hunk *current_hunk;

	bool trivial_file_match;
};

git_blame *git_blame__alloc(
	git_repository *repo,
	git_blame_options opts,
	const char *path);
