/* vi:sw=6
 * Copyright (c) 2002 Michael Ruff (mruff at chiaro.com)
 *
 *    This source code is free software; you can redistribute it
 *    and/or modify it in source code form under the terms of the GNU
 *    General Public License as published by the Free Software
 *    Foundation; either version 2 of the License, or (at your option)
 *    any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */
#if !defined(WINNT)
#ident "$Id: a_fetch_tfarg.c,v 1.1 2002/06/07 02:58:58 steve Exp $"
#endif

#include  <vpi_user.h>
#include  <acc_user.h>

/*
 * acc_fetch_tfarg routines implemented using VPI interface
 */
int acc_fetch_tfarg_int(int n)
{
      vpiHandle sys_h, sys_i, arg_h = 0;
      s_vpi_value value;
      int rtn;

      sys_h = vpi_handle(vpiSysTfCall, 0);
      sys_i = vpi_iterate(vpiArgument, sys_h);

      /* scan to nth argument */
      while (n > 0 && (arg_h = vpi_scan(sys_i))) n--;

      if (arg_h) {
	    value.format=vpiIntVal;
	    vpi_get_value(arg_h, &value);
	    rtn = value.value.integer; 
      } else {
	    rtn = 0;
      }

      return rtn;
}

char *acc_fetch_tfarg_str(int n)
{
      vpiHandle sys_h, sys_i, arg_h = 0;
      s_vpi_value value;
      char *rtn;

      sys_h = vpi_handle(vpiSysTfCall, 0);
      sys_i = vpi_iterate(vpiArgument, sys_h);

      /* scan to nth argument */
      while (n > 0 && (arg_h = vpi_scan(sys_i))) n--;

      if (arg_h) {
	    value.format=vpiStringVal;
	    vpi_get_value(arg_h, &value);
	    rtn = value.value.str; 
      } else {
	    rtn = (char *) 0;
      }

      return rtn;
}

/*
 * $Log: a_fetch_tfarg.c,v $
 * Revision 1.1  2002/06/07 02:58:58  steve
 *  Add a bunch of acc/tf functions. (mruff)
 *
 */
