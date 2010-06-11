/* *** Copyright 2010 Teemu Vasama ***
 * This program is licensed under the terms of the GPLv3 license.
 * You can find it in the LICENSE file or from <http://www.gnu.org/licenses/>.
 * This software comes with NO WARRANTY WHATSOEVER! */

#include "qt_main.h"

int QtMain(int argc, char *argv[])
{
	QApplication app(argc, argv);
		
	Counter counter;	
	counter.show();
		
	return app.exec();
}