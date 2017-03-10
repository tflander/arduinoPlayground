# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# For each target create a dummy rule so the target does not have to exist
/common/workspaces/arduino/myLibraries/src/libRGBColorFade.a:


# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.RGBColorFade:
PostBuild.faderTests:
PostBuild.RGBColorFade: /common/workspaces/arduino/myLibraries/test/faderTests
/common/workspaces/arduino/myLibraries/test/faderTests:\
	/common/workspaces/arduino/myLibraries/src/libRGBColorFade.a
	/bin/rm -f /common/workspaces/arduino/myLibraries/test/faderTests


