======
astyle
======

This is a modified version of astyle: http://astyle.sourceforge.net

Our intention is to patch astyle to follow the Steinwurf coding style
as closely as possible: http://docs.steinwurf.com/coding_style.html

Steinwurf uses heavily-templated C++11 code that can be a true challenge
for a code formatting tool.

Quick start
-----------

If you already installed a C++11 compiler, git and python on your system,
then you can clone this repository to a suitable folder::

    git clone git@github.com:steinwurf/astyle.git

Configure and build the project (use the ``cxx_default`` mkspec, because
fabric will look for the ``astyle`` binary at this default location)::

    cd astyle
    python waf configure --cxx_mkspec=cxx_default
    python waf build

Running astyle manually
-----------------------

First of all, you should copy the ``.astylerc`` options file to your home
folder.

On Unix systems::

    cp .astylerc ~

On Windows::

    copy .astylerc %USERPROFILE%\astylerc

After this, you can call ``astyle`` to format a single file (be careful,
because **it will not make a backup** for the original file)::

    build/cxx_default/astyle test.cpp --print-changes

The ``--print-changes`` option prints out every line that is changed
during the formatting. This is especially useful with the ``--dry-run``
option that will not write any modifications to the file::

    build/cxx_default/astyle test.cpp --print-changes --dry-run

**Warning**: Be careful about the working directory if you invoke the
following command, because you can accidentally format a lot of files!

You can format all C/C++ source files within the current directory with the
recursive search (``-R``) option::

    cd my-project
    path/to/astyle -Q -R *.cpp *.hpp *.c *.h --print-changes

With the ``-Q`` option, astyle will only display information about the
formatted files (it will not list the unchanged files).

Instead of copying ``.astylerc`` to your home folder, you can also specify
the options file directly. The file can change in the future, so this is the
recommended solution if you want to invoke astyle from your IDE::

    cd my-project
    path/to/astyle --options=/path/to/.astylerc -Q -R *.cpp *.hpp *.c *.h --print-changes

Running astyle with fabric (for Steinwurf projects)
---------------------------------------------------

For convenience, we also have fabric tasks to run astyle on Steinwurf projects.

The ``astyle.format_code`` task will format all C/C++ source files in the
selected project::

    fab astyle.format_code:my-project

You can also add ``update_astyle=True`` to automatically update the astyle
project and build the latest binary::

    fab astyle.format_code:my-project,update_astyle=True

The ``astyle.check_code`` task will not make any changes in the C/C++ source
files, it will only print the required changes in the selected project::

    fab astyle.check_code:my-project

Integrating astyle with the Atom text editor
--------------------------------------------

After building astyle, please install the following packages in Atom::

    apm install formatter
    apm install formatter-astyle

In the settings for ``formatter-astyle``, point to the astyle binary in
``build/cxx_default`` and to the ``.astylerc`` file in the root of this
repository.

The keyboard shortcuts can be found in the settings for the formatter package.
