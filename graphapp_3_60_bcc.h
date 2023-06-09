/*
 *  GraphApp programming interface.
 *
 *  Include this header file to use the abbreviated
 *  function names.
 */

/* FGB */
#ifndef _graphapp_3_60_bcc_h_
#define _graphapp_3_60_bcc_h_
/* end FGB */



/* #include <app.h> */
#include <app_3_60_bcc.h>

#define activate_control             app_activate_control
#define add_button                   app_add_button
#define add_check_box                app_add_check_box
#define add_control                  app_add_control
#define add_drop_field               app_add_drop_field
#define add_drop_list                app_add_drop_list
#define add_field                    app_add_field
#define add_image_button             app_add_image_button
#define add_image_check_box          app_add_image_check_box
#define add_image_label              app_add_image_label
#define add_label                    app_add_label
#define add_list_box                 app_add_list_box
#define add_note_button              app_add_note_button
#define add_password_field           app_add_password_field
#define add_radio_button             app_add_radio_button
#define add_radio_group              app_add_radio_group
#define add_scroll_bar               app_add_scroll_bar
#define add_separator                app_add_separator
#define add_splitter                 app_add_splitter
#define add_tab_button               app_add_tab_button
#define add_text_box                 app_add_text_box
#define alloc                        app_alloc
#define append_to_image_list         app_append_to_image_list
#define arm                          app_arm
#define ask_file_open                app_ask_file_open
#define ask_file_save                app_ask_file_save
#define ask_ok                       app_ask_ok
#define ask_ok_cancel                app_ask_ok_cancel
#define ask_string                   app_ask_string
#define ask_yes_no                   app_ask_yes_no
#define ask_yes_no_cancel            app_ask_yes_no_cancel
#define attach_to_control            app_attach_to_control
#define attach_to_window             app_attach_to_window
#define beep                         app_beep
#define bitmap_to_image              app_bitmap_to_image
#define bring_control_to_front       app_bring_control_to_front
#define center_rect                  app_center_rect
#define change_default_font          app_change_default_font
#define change_list_box              app_change_list_box
#define change_scroll_bar            app_change_scroll_bar
#define check                        app_check
#define check_menu_item              app_check_menu_item
#define clear_text                   app_clear_text
#define clip_line_to_rect            app_clip_line_to_rect
#define clip_rect                    app_clip_rect
#define close_file                   app_close_file
#define close_folder                 app_close_folder
#define colors_equal                 app_rgbs_equal
#define colours_equal                app_rgbs_equal
#define copy_bits                    app_copy_bits
#define copy_image                   app_copy_image
#define copy_rect(g,dp,src,sr)       ((g)->copy_rect((g),(dp),(src),(sr)))
#define copy_region                  app_copy_region
#define copy_rgbs                    app_copy_rgbs
#define copy_string                  app_copy_string
#define copy_text                    app_copy_text
#define correct_utf8                 app_correct_utf8
#define current_folder               app_current_folder
#define current_time                 app_current_time
#define cut_text                     app_cut_text
#define debug_memory                 app_debug_memory
#define del_all_windows              app_del_all_windows
#define del_app                      app_del_app
#define del_bitmap                   app_del_bitmap
#define del_control                  app_del_control
#define del_cursor                   app_del_cursor
#define del_font                     app_del_font
#define del_graphics                 app_del_graphics
#define del_image                    app_del_image
#define del_image_list               app_del_image_list
#define del_image_reader             app_del_image_reader
#define del_menu                     app_del_menu
#define del_menu_bar                 app_del_menu_bar
#define del_menu_item                app_del_menu_item
#define del_palette                  app_del_palette
#define del_region                   app_del_region
#define del_string                   app_del_string
#define del_string_table             app_del_string_table
#define del_timer                    app_del_timer
#define del_window                   app_del_window
#define delay                        app_delay
#define disable                      app_disable
#define disable_menu_item            app_disable_menu_item
#define disarm                       app_disarm
#define do_event                     app_do_event
#define draw_all                     app_draw_all
#define draw_arc                     app_draw_arc
#define draw_control                 app_draw_control
#define draw_ellipse                 app_draw_ellipse
#define draw_image                   app_draw_image
#define draw_image_brighter          app_draw_image_brighter
#define draw_image_darker            app_draw_image_darker
#define draw_image_greyscale         app_draw_image_greyscale
#define draw_image_monochrome        app_draw_image_monochrome
#define draw_line(g,p1,p2)           ((g)->draw_line((g),(p1),(p2)))
#define draw_point                   app_draw_point
#define draw_polygon                 app_draw_polygon
#define draw_polyline                app_draw_polyline
#define draw_rect                    app_draw_rect
#define draw_round_rect              app_draw_round_rect
#define draw_shadow_rect             app_draw_shadow_rect
#define draw_text                    app_draw_text
#define draw_utf8(g,p,utf8,nb)       ((g)->draw_utf8((g),(p),(utf8),(nb)))
#define draw_window                  app_draw_window
#define enable                       app_enable
#define enable_menu_item             app_enable_menu_item
#define error                        app_error
#define exec                         app_exec
#define file_has_resources           app_file_has_resources
#define file_info                    app_file_info
#define file_size                    app_file_size
#define file_time                    app_file_time
#define fill_arc                     app_fill_arc
#define fill_ellipse                 app_fill_ellipse
#define fill_polygon                 app_fill_polygon
#define fill_rect(g,r)               ((g)->fill_rect((g),(r)))
#define fill_region                  app_fill_region
#define fill_round_rect              app_fill_round_rect
#define find_best_cursor_size        app_find_best_cursor_size
#define find_default_font            app_find_default_font
#define find_image_format            app_find_image_format
#define flash_control                app_flash_control
#define font_char_info               app_font_char_info
#define font_height                  app_font_height
#define font_width                   app_font_width
#define form_file_path               app_form_file_path
#define free                         app_free
#define get_bitmap_area              app_get_bitmap_area
#define get_bitmap_graphics          app_get_bitmap_graphics
#define get_clipboard_text           app_get_clipboard_text
#define get_control_area             app_get_control_area
#define get_control_background       app_get_control_background
#define get_control_cursor           app_get_control_cursor
#define get_control_data             app_get_control_data
#define get_control_font             app_get_control_font
#define get_control_foreground       app_get_control_foreground
#define get_control_graphics         app_get_control_graphics
#define get_control_image            app_get_control_image
#define get_control_text             app_get_control_text
#define get_control_value            app_get_control_value
#define get_cursor_position          app_get_cursor_position
#define get_file_name                app_get_file_name
#define get_image_area               app_get_image_area
#define get_image_graphics           app_get_image_graphics
#define get_list_box_item            app_get_list_box_item
#define get_menu_bar_font            app_get_menu_bar_font
#define get_menu_font                app_get_menu_font
#define get_menu_foreground          app_get_menu_foreground
#define get_menu_item_font           app_get_menu_item_font
#define get_menu_item_foreground     app_get_menu_item_foreground
#define get_menu_item_value          app_get_menu_item_value
#define get_mouse_event              app_get_mouse_event
#define get_standard_cursor          app_get_standard_cursor
#define get_string                   app_get_string
#define get_window_area              app_get_window_area
#define get_window_background        app_get_window_background
#define get_window_data              app_get_window_data
#define get_window_graphics          app_get_window_graphics
#define get_window_palette           app_get_window_palette
#define get_window_title             app_get_window_title
#define get_window_under_cursor      app_get_window_under_cursor
#define has_focus                    app_has_focus
#define hide_all_windows             app_hide_all_windows
#define hide_control                 app_hide_control
#define hide_window                  app_hide_window
#define highlight                    app_highlight
#define image_convert_32_to_8        app_image_convert_32_to_8
#define image_convert_8_to_32        app_image_convert_8_to_32
#define image_find_colour            app_image_find_colour
#define image_has_transparent_pixels app_image_has_transparent_pixels
#define image_sort_palette           app_image_sort_palette
#define image_to_bitmap              app_image_to_bitmap
#define insert_node                  app_insert_node
#define insert_text                  app_insert_text
#define inset_rect                   app_inset_rect
#define intersect_region             app_intersect_region
#define intersect_region_with_rect   app_intersect_region_with_rect
#define is_armed                     app_is_armed
#define is_checked                   app_is_checked
#define is_enabled                   app_is_enabled
#define is_highlighted               app_is_highlighted
#define is_visible                   app_is_visible
#define locate_control               app_locate_control
#define locate_node                  app_locate_node
#define main_loop                    app_main_loop
#define make_folder                  app_make_folder
#define malloc                       app_alloc
#define manager_hbox                 app_manager_hbox
#define manager_vbox                 app_manager_vbox
#define memory_used                  app_memory_used
#define menu_item_is_checked         app_menu_item_is_checked
#define menu_item_is_enabled         app_menu_item_is_enabled
#define move_control                 app_move_control
#define move_region                  app_move_region
#define move_window                  app_move_window
#define new_app                      app_new_app
#define new_argb                     app_new_argb
#define new_bitmap                   app_new_bitmap
#define new_button                   app_new_button
#define new_check_box                app_new_check_box
#define new_color                    app_new_rgb
#define new_colour                   app_new_rgb
#define new_control                  app_new_control
#define new_cursor                   app_new_cursor
#define new_drop_field               app_new_drop_field
#define new_drop_list                app_new_drop_list
#define new_field                    app_new_field
#define new_font                     app_new_font
#define new_image                    app_new_image
#define new_image_button             app_new_image_button
#define new_image_check_box          app_new_image_check_box
#define new_image_label              app_new_image_label
#define new_image_list               app_new_image_list
#define new_image_reader             app_new_image_reader
#define new_label                    app_new_label
#define new_list_box                 app_new_list_box
#define new_menu                     app_new_menu
#define new_menu_bar                 app_new_menu_bar
#define new_menu_item                app_new_menu_item
#define new_note_button              app_new_note_button
#define new_palette                  app_new_palette
#define new_password_field           app_new_password_field
#define new_point                    app_new_point
#define new_radio_button             app_new_radio_button
#define new_radio_group              app_new_radio_group
#define new_rect                     app_new_rect
#define new_rect_region              app_new_rect_region
#define new_region                   app_new_region
#define new_rgb                      app_new_rgb
#define new_scroll_bar               app_new_scroll_bar
#define new_separator                app_new_separator
#define new_splitter                 app_new_splitter
#define new_string_table             app_new_string_table
#define new_sub_menu                 app_new_sub_menu
#define new_tab_button               app_new_tab_button
#define new_text_box                 app_new_text_box
#define new_timer                    app_new_timer
#define new_window                   app_new_window
#define on_control_action            app_on_control_action
#define on_control_deletion          app_on_control_deletion
#define on_control_key_action        app_on_control_key_action
#define on_control_key_down          app_on_control_key_down
#define on_control_mouse_down        app_on_control_mouse_down
#define on_control_mouse_drag        app_on_control_mouse_drag
#define on_control_mouse_move        app_on_control_mouse_move
#define on_control_mouse_up          app_on_control_mouse_up
#define on_control_redraw            app_on_control_redraw
#define on_control_refocus           app_on_control_refocus
#define on_control_resize            app_on_control_resize
#define on_control_update            app_on_control_update
#define on_window_close              app_on_window_close
#define on_window_key_action         app_on_window_key_action
#define on_window_key_down           app_on_window_key_down
#define on_window_mouse_down         app_on_window_mouse_down
#define on_window_mouse_drag         app_on_window_mouse_drag
#define on_window_mouse_move         app_on_window_mouse_move
#define on_window_mouse_up           app_on_window_mouse_up
#define on_window_move               app_on_window_move
#define on_window_redraw             app_on_window_redraw
#define on_window_resize             app_on_window_resize
#define open_file                    app_open_file
#define open_folder                  app_open_folder
#define open_resource                app_open_resource
#define palette_translation          app_palette_translation
#define parent_window(c)             ((c)->win)
#define pass_event                   app_pass_event
#define paste_text                   app_paste_text
#define peek_event                   app_peek_event
#define place_window_controls        app_place_window_controls
#define point_in_rect                app_point_in_rect
#define point_in_region              app_point_in_region
#define points_equal                 app_points_equal
#define pop_up_list                  app_pop_up_list
#define portable_draw_line           app_portable_draw_line
#define process_events               app_process_events
#define read_folder                  app_read_folder
#define read_image                   app_read_image
#define read_image_file              app_read_image_file
#define read_image_progressively     app_read_image_progressively
#define read_latin1_file             app_read_latin1_file
#define read_latin1_line             app_read_latin1_line
#define read_utf8_char               app_read_utf8_char
#define read_utf8_file               app_read_utf8_file
#define read_utf8_line               app_read_utf8_line
#define realloc                      app_realloc
#define rect_abs                     app_rect_abs
#define rect_in_rect                 app_rect_in_rect
#define rect_in_region               app_rect_in_region
#define rect_intersects_rect         app_rect_intersects_rect
#define rect_intersects_region       app_rect_intersects_region
#define rects_equal                  app_rects_equal
#define redraw_control               app_redraw_control
#define redraw_control_rect          app_redraw_control_rect
#define redraw_rect                  app_redraw_rect
#define redraw_window                app_redraw_window
#define regex_match                  app_regex_match
#define region_is_empty              app_region_is_empty
#define regions_equal                app_regions_equal
#define remove_control               app_remove_control
#define remove_file                  app_remove_file
#define remove_folder                app_remove_folder
#define remove_node                  app_remove_node
#define rename_file                  app_rename_file
#define rename_folder                app_rename_folder
#define reset_list_box               app_reset_list_box
#define rgbs_equal                   app_rgbs_equal
#define scale_image                  app_scale_image
#define select_text                  app_select_text
#define send_control_to_back         app_send_control_to_back
#define set_clip_rect                app_set_clip_rect
#define set_clip_region              app_set_clip_region
#define set_clipboard_text           app_set_clipboard_text
#define set_color                    app_set_rgb
#define set_colour                   app_set_rgb
#define set_control_area             app_set_control_area
#define set_control_autosize         app_set_control_autosize
#define set_control_background       app_set_control_background
#define set_control_border           app_set_control_border
#define set_control_cursor           app_set_control_cursor
#define set_control_data             app_set_control_data
#define set_control_font             app_set_control_font
#define set_control_foreground       app_set_control_foreground
#define set_control_gap              app_set_control_gap
#define set_control_image            app_set_control_image
#define set_control_layout           app_set_control_layout
#define set_control_text             app_set_control_text
#define set_control_tip              app_set_control_tip
#define set_control_value            app_set_control_value
#define set_current_folder           app_set_current_folder
#define set_cursor_position          app_set_cursor_position
#define set_default_font             app_set_default_font
#define set_field_allowed_chars      app_set_field_allowed_chars
#define set_field_allowed_width      app_set_field_allowed_width
#define set_field_disallowed_chars   app_set_field_disallowed_chars
#define set_focus                    app_set_focus
#define set_font                     app_set_font
#define set_image_cmap               app_set_image_cmap
#define set_line_width               app_set_line_width
#define set_list_box_item            app_set_list_box_item
#define set_menu_bar_font            app_set_menu_bar_font
#define set_menu_font                app_set_menu_font
#define set_menu_foreground          app_set_menu_foreground
#define set_menu_item_font           app_set_menu_item_font
#define set_menu_item_foreground     app_set_menu_item_foreground
#define set_menu_item_value          app_set_menu_item_value
#define set_paint_mode               app_set_paint_mode
#define set_rgb                      app_set_rgb
#define set_rgbindex                 app_set_rgbindex
#define set_string                   app_set_string
#define set_text_direction           app_set_text_direction
#define set_window_background        app_set_window_background
#define set_window_cursor            app_set_window_cursor
#define set_window_data              app_set_window_data
#define set_window_icon              app_set_window_icon
#define set_window_palette           app_set_window_palette
#define set_window_title             app_set_window_title
#define set_xor_mode                 app_set_xor_mode
#define show_control                 app_show_control
#define show_window                  app_show_window
#define size_control                 app_size_control
#define size_window                  app_size_window
#define subtract_region              app_subtract_region
#define text_height                  app_text_height
#define text_line_length             app_text_line_length
#define text_selection               app_text_selection
#define text_width                   app_text_width
#define texture_rect                 app_texture_rect
#define traverse_string_table        app_traverse_string_table
#define uncheck                      app_uncheck
#define uncheck_menu_item            app_uncheck_menu_item
#define unhighlight                  app_unhighlight
#define unicode_char_to_utf8         app_unicode_char_to_utf8
#define unicode_to_utf8              app_unicode_to_utf8
#define union_region                 app_union_region
#define union_region_with_rect       app_union_region_with_rect
#define utf8_char_to_unicode         app_utf8_char_to_unicode
#define utf8_is_ascii                app_utf8_is_ascii
#define utf8_is_latin1               app_utf8_is_latin1
#define utf8_length                  app_utf8_length
#define utf8_to_latin1               app_utf8_to_latin1
#define utf8_to_unicode              app_utf8_to_unicode
#define wait_event                   app_wait_event
#define write_image                  app_write_image
#define write_latin1                 app_write_latin1
#define write_utf8                   app_write_utf8
#define xor_region                   app_xor_region
#define zero_alloc                   app_zero_alloc


/* FGB */
#endif
/* end FGB */
