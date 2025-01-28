# Minimal makefile for Sphinx documentation
#

# You can set these variables from the command line, and also
# from the environment for the first two.
SPHINXOPTS    ?=
SPHINXBUILD   ?= sphinx-build
SOURCEDIR     = .
BUILDDIR      = _build

# Put it first so that "make" without argument is like "make help".
help:
	@$(SPHINXBUILD) -M help "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)

.PHONY: help Makefile ja en update-po

ja:
	$(SPHINXBUILD) -M html "$(SOURCEDIR)" "$(BUILDDIR)/ja" $(SPHINXOPTS) $(O)
en:
	LANGUAGE=en $(SPHINXBUILD) -M html "$(SOURCEDIR)" "$(BUILDDIR)/en" $(SPHINXOPTS) $(O)
update-po:
	$(SPHINXBUILD) -M gettext "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)
	sphinx-intl update -p "$(BUILDDIR)/gettext" -l en

# Catch-all target: route all unknown targets to Sphinx using the new
# "make mode" option.  $(O) is meant as a shortcut for $(SPHINXOPTS).
%: Makefile
	@$(SPHINXBUILD) -M $@ "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)
