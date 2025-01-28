# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

import tomllib
import os

with open("../pyproject.toml", "rb") as f:
    pyproject = tomllib.load(f)
version = pyproject["project"]["version"]

language = os.getenv("LANGUAGE", "ja")
ドキュメント = {
    "ja": "ドキュメント",
    "en": "Documentation",
}
project = f'acl-cpp-python v{version} {ドキュメント[language]}'
release = f'v{version}'
copyright = 'CC0 1.0'
author = 'tatyam'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

locale_dirs = ['locale/']
extensions = ['myst_parser', 'sphinx_copybutton']
myst_enable_extensions = [
    "dollarmath",
]

templates_path = ['_templates']
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_rtd_theme'
html_static_path = ['_static']
