/*                                 SUCHAI
 *                      NANOSATELLITE FLIGHT SOFTWARE
 *
 *      Copyright 2013, Carlos Gonzalez Cortes, carlgonz@ug.uchile.cl
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "cmdConsole.h"
#include "cmdRepository.h"

cmdFunction conFunction[CON_NCMD];
int con_sysReq[CON_NCMD];

void con_onResetCmdCON(void){
    conFunction[(unsigned char)con_id_help] = con_help;
    con_sysReq[(unsigned char)con_id_help]  = CMD_SYSREQ_MIN;
    conFunction[(unsigned char)con_id_promt] = con_promt;
    con_sysReq[(unsigned char)con_id_promt]  = CMD_SYSREQ_MIN;
    conFunction[(unsigned char)con_id_error_cmd_toolong] = con_error_cmd_toolong;
    con_sysReq[(unsigned char)con_id_error_cmd_toolong]  = CMD_SYSREQ_MIN;
    conFunction[(unsigned char)con_id_debug_msg] = con_debug_msg;
    con_sysReq[(unsigned char)con_id_debug_msg]  = CMD_SYSREQ_MIN;
    conFunction[(unsigned char)con_id_error_unknown_cmd] = con_error_unknown_cmd;
    con_sysReq[(unsigned char)con_id_error_unknown_cmd]  = CMD_SYSREQ_MIN;
    conFunction[(unsigned char)con_id_error_invalid_arg] = con_error_invalid_arg;
    con_sysReq[(unsigned char)con_id_error_invalid_arg]  = CMD_SYSREQ_MIN;
    conFunction[(unsigned char)con_id_error_count_arg] = con_error_count_arg;
    con_sysReq[(unsigned char)con_id_error_count_arg]  = CMD_SYSREQ_MIN;
    
    cmd_add("test", con_debug_msg, "");
    cmd_add("none", con_error_unknown_cmd, "");
    cmd_add("none1", con_error_unknown_cmd, "");
    cmd_add("none2", con_error_unknown_cmd, "");
}

/**
 * Display a generic quantity argument error
 * @param param void
 * @return 1 - OK
 */
int con_error_count_arg(void *param)
{
    printf("[Console Error] Arguments quantity dismatch\r\n"); //Type con_help for available commands\r\n");
    return 1;
}

/**
 * Display a generic invalid argument error
 * @param param void
 * @return 1 - OK
 */
int con_error_invalid_arg(void *param)
{
    printf("[Console Error] Arguments invalid\r\n"); //Type con_help for available commands\r\n");
    return 1;
}

/**
 * Display a generic unknown command error
 * @param param void
 * @return 1 - OK
 */
int  con_error_unknown_cmd(void *param)
{
    printf("[Console Error] Unknown command\r\n"); //Type con_help for available commands\r\n");
    return 1;
}

/**
 * Display a generic command too long error
 * @param param void
 * @return 1 - OK
 */
int  con_error_cmd_toolong(void *param)
{
    printf("[Console Error] Command too long\r\n"); //Type con_help for available commands\r\n");
    return 1;
}

/**
 * Display a test message
 * @param param void message as char array
 * @return 1 - OK, 0 fail
 */
int  con_debug_msg(void *param)
{
    char *msg = (char *)param;
    if(msg)
    {
        printf("[Debug Msg] ");
        printf((char *) msg);
        printf("\r\n");
        return 1;
    }
    return 0;
}

/**
 * Display help text.
 * Add custom help text inside this funcion
 * 
 * @param param void
 * @return 1 - OK
 */
int con_help(void *param)
{
    printf("=================== CONSOLE HELP ===================\r\n");
    /*--------------------- PPC HELP ------------------*/
    printf("ppc_reset          = Software resets the PIC.\r\n");
    printf("ppc_newosc <arg1>  = Set a new Oscillator source for Fcy.\r\n");
    printf("ppc_osc            = Returns the Oscillator source of Fcy.\r\n");
    printf("ppc_enwdt <arg1>   = Enable or disable the WDT.\r\n");
    /*--------------------- CON HELP ------------------*/
    printf("con_hist [arg1]    = Show history of cmd or use a listed cmd.\r\n");
    printf("con_help           = Show this help. con_help\r\n");
    printf("====================================================\r\n");
    
    //printf("\r\n>>");

    return 1;
}

/**
 * Display a generic propmp
 * @param param void
 * @return 1 - OK
 */
int con_promt(void *param)
{
    printf(">>");
    return 1;
}
