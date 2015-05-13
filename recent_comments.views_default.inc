<?php
/**
 * Implements hook_views_default_views().
 */
function recent_comments_views_default_views() {

$view = new view();
$view->name = 'comments_recent';
$view->description = 'Contains recent comments by comment author and links to the content they came from';
$view->tag = 'default';
$view->base_table = 'comment';
$view->human_name = 'Recent comments';
$view->core = 0;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Recent comments';
$handler->display->display_options['use_more_always'] = TRUE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '20';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['row_plugin'] = 'fields';
/* Relationship: Comment: Content */
$handler->display->display_options['relationships']['nid']['id'] = 'nid';
$handler->display->display_options['relationships']['nid']['table'] = 'comment';
$handler->display->display_options['relationships']['nid']['field'] = 'nid';
/* Relationship: Comment: Author */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'comment';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Field: Comment: Author */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'comment';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
/* Field: Comment: Title */
$handler->display->display_options['fields']['subject']['id'] = 'subject';
$handler->display->display_options['fields']['subject']['table'] = 'comment';
$handler->display->display_options['fields']['subject']['field'] = 'subject';
$handler->display->display_options['fields']['subject']['label'] = '';
/* Field: Comment: Comment */
$handler->display->display_options['fields']['comment_body']['id'] = 'comment_body';
$handler->display->display_options['fields']['comment_body']['table'] = 'field_data_comment_body';
$handler->display->display_options['fields']['comment_body']['field'] = 'comment_body';
$handler->display->display_options['fields']['comment_body']['label'] = '';
$handler->display->display_options['fields']['comment_body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['comment_body']['element_default_classes'] = FALSE;
/* Field: Comment: Updated date */
$handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['table'] = 'comment';
$handler->display->display_options['fields']['timestamp']['field'] = 'changed';
$handler->display->display_options['fields']['timestamp']['label'] = '';
$handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
/* Field: Comment: Author */
$handler->display->display_options['fields']['name_1']['id'] = 'name_1';
$handler->display->display_options['fields']['name_1']['table'] = 'comment';
$handler->display->display_options['fields']['name_1']['field'] = 'name';
$handler->display->display_options['fields']['name_1']['label'] = '';
$handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
/* Field: Comment: Comment */
$handler->display->display_options['fields']['comment_body_1']['id'] = 'comment_body_1';
$handler->display->display_options['fields']['comment_body_1']['table'] = 'field_data_comment_body';
$handler->display->display_options['fields']['comment_body_1']['field'] = 'comment_body';
/* Sort criterion: Comment: Updated date */
$handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['sorts']['timestamp']['table'] = 'comment';
$handler->display->display_options['sorts']['timestamp']['field'] = 'changed';
$handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'semanticviews_default';
$handler->display->display_options['style_options']['group']['element_type'] = 'div';
$handler->display->display_options['style_options']['group']['class'] = 'view-recent-comments';
$handler->display->display_options['style_options']['list']['element_type'] = 'ul';
$handler->display->display_options['style_options']['list']['class'] = 'listing-comments';
$handler->display->display_options['style_options']['row']['element_type'] = 'li';
$handler->display->display_options['style_options']['row']['class'] = 'listing-row';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'semanticviews_fields';
$handler->display->display_options['row_options']['skip_blank'] = 1;
$handler->display->display_options['row_options']['semantic_html'] = array(
  'field_display_name' => array(
    'element_type' => 'p',
    'class' => '',
  ),
  'title' => array(
    'element_type' => 'p',
    'class' => '',
  ),
  'comment_body' => array(
    'element_type' => 'p',
    'class' => 'comment-short',
  ),
  'timestamp' => array(
    'element_type' => 'p',
    'class' => 'comment-date',
  ),
);
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Comment count */
$handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
$handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
$handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
$handler->display->display_options['fields']['comment_count']['relationship'] = 'nid';
$handler->display->display_options['fields']['comment_count']['label'] = '';
$handler->display->display_options['fields']['comment_count']['exclude'] = TRUE;
$handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
/* Field: User: Display Name */
$handler->display->display_options['fields']['field_display_name']['id'] = 'field_display_name';
$handler->display->display_options['fields']['field_display_name']['table'] = 'field_data_field_display_name';
$handler->display->display_options['fields']['field_display_name']['field'] = 'field_display_name';
$handler->display->display_options['fields']['field_display_name']['relationship'] = 'uid';
$handler->display->display_options['fields']['field_display_name']['label'] = '';
$handler->display->display_options['fields']['field_display_name']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_display_name']['alter']['text'] = '[field_display_name] & [comment_count] others';
$handler->display->display_options['fields']['field_display_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_display_name']['element_default_classes'] = FALSE;
/* Field: User: Link */
$handler->display->display_options['fields']['view_user']['id'] = 'view_user';
$handler->display->display_options['fields']['view_user']['table'] = 'users';
$handler->display->display_options['fields']['view_user']['field'] = 'view_user';
$handler->display->display_options['fields']['view_user']['relationship'] = 'uid';
$handler->display->display_options['fields']['view_user']['label'] = '';
$handler->display->display_options['fields']['view_user']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['view_user']['alter']['text'] = '[field_display_name] & [comment_count] others';
$handler->display->display_options['fields']['view_user']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['view_user']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_user']['element_default_classes'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'nid';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Comment: Comment */
$handler->display->display_options['fields']['comment_body']['id'] = 'comment_body';
$handler->display->display_options['fields']['comment_body']['table'] = 'field_data_comment_body';
$handler->display->display_options['fields']['comment_body']['field'] = 'comment_body';
$handler->display->display_options['fields']['comment_body']['label'] = '';
$handler->display->display_options['fields']['comment_body']['exclude'] = TRUE;
$handler->display->display_options['fields']['comment_body']['alter']['max_length'] = '50';
$handler->display->display_options['fields']['comment_body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['comment_body']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['comment_body']['settings'] = array(
  'trim_length' => '50',
);
/* Field: Comment: View link */
$handler->display->display_options['fields']['view_comment']['id'] = 'view_comment';
$handler->display->display_options['fields']['view_comment']['table'] = 'comment';
$handler->display->display_options['fields']['view_comment']['field'] = 'view_comment';
$handler->display->display_options['fields']['view_comment']['label'] = '';
$handler->display->display_options['fields']['view_comment']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['view_comment']['alter']['text'] = '[comment_body]';
$handler->display->display_options['fields']['view_comment']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['view_comment']['alter']['max_length'] = '60';
$handler->display->display_options['fields']['view_comment']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['view_comment']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['view_comment']['element_default_classes'] = FALSE;
/* Field: Comment: Updated date */
$handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
$handler->display->display_options['fields']['timestamp']['table'] = 'comment';
$handler->display->display_options['fields']['timestamp']['field'] = 'changed';
$handler->display->display_options['fields']['timestamp']['label'] = '';
$handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['timestamp']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['timestamp']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['timestamp']['date_format'] = 'raw time ago';
$handler->display->display_options['fields']['timestamp']['timezone'] = 'America/Phoenix';

  //Add view to list of views to provide
  $views[$view->name] = $view;

  return $views;
}
