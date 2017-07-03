<?php
/**
 * @file
 * Page callbacks for csas_ist.
 */

function csas_ist_pages_example() {
  $build['wr'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array('csas-ist-example')
    ),
    '#attached' => array(
      'css' => array(drupal_get_path('module', 'csas_ist') . '/css/csas_ist_demo.css'),
    )
  );

  $content = '<div class="csas-ist-item csas-ist-item--width2"></div>
  <div class="csas-ist-item csas-ist-item--height2"></div>
  <div class="csas-ist-item"></div>
  <div class="csas-ist-item"></div>
  <div class="csas-ist-item csas-ist-item--width2 csas-ist-item--height2"></div>
  <div class="csas-ist-item csas-ist-item--width2"></div>
  <div class="csas-ist-item csas-ist-item--width2"></div>
  <div class="csas-ist-item csas-ist-item--height2"></div>
  <div class="csas-ist-item"></div>
  <div class="csas-ist-item csas-ist-item--width2"></div>
  <div class="csas-ist-item csas-ist-item--height2"></div>
  <div class="csas-ist-item"></div>
  <div class="csas-ist-item"></div>';
  $masonry = (object)array('columnWidth' => 100);
  $dat_opt = array(
    'itemSelector' => '.csas-ist-item',
    'masonry' => $masonry
  );
  $dat_opt = (object)$dat_opt;
  $build['wr']['masonry'] = array(
    '#prefix' => '<h2>Isotope - masonry layout mode</h2>',
    '#type' => 'container',

    '#attached' => array(
      'library' => array(array('csas_ist', 'csas_ist'))
    ),
    '#attributes' => array(
      'class' => array(
        'csas-ist-grid',
        'csas-ist-demo',
      ),
      'data-options' => drupal_json_encode($dat_opt)
    ),
    'content' => array('#markup' => $content),
  );

  //Isotope - masonry fluid sizing
  $content = '<div class="csas-ist-sizer"></div>
  <div class="csas-ist-item csas-ist-item--width2"></div>
  <div class="csas-ist-item csas-ist-item--height2"></div>
  <div class="csas-ist-item"></div>
  <div class="csas-ist-item"></div>
  <div class="csas-ist-item csas-ist-item--width2 csas-ist-item--height2"></div>
  <div class="csas-ist-item csas-ist-item--width2"></div>
  <div class="csas-ist-item csas-ist-item--width2"></div>
  <div class="csas-ist-item csas-ist-item--height2"></div>
  <div class="csas-ist-item"></div>
  <div class="csas-ist-item csas-ist-item--width2"></div>
  <div class="csas-ist-item csas-ist-item--height2"></div>
  <div class="csas-ist-item"></div>
  <div class="csas-ist-item"></div>';
  $masonry = (object)array('columnWidth' => '.csas-ist-sizer');
  $dat_opt = array(
    'itemSelector' => '.csas-ist-item',
    'percentPosition' => true,
    'masonry' => $masonry
  );
  $dat_opt = (object)$dat_opt;
  $build['wr']['masonry_fluid'] = array(
    '#prefix' => '<h2>Isotope - masonry fluid sizing</h2>',
    '#type' => 'container',

    '#attached' => array(
      'library' => array(array('csas_ist', 'csas_ist'))
    ),
    '#attributes' => array(
      'class' => array(
        'csas-ist-grid',
        'csas-ist-mns-fld',
      ),
      'data-options' => drupal_json_encode($dat_opt)
    ),
    'content' => array('#markup' => $content),
  );


  //packery http://isotope.metafizzy.co/layout-modes.html#packery
  $content = '
  <div class="csas-ist-item csas-ist-item--width2"></div>
  <div class="csas-ist-item csas-ist-item--height2"></div>
  <div class="csas-ist-item"></div>
  <div class="csas-ist-item"></div>
  <div class="csas-ist-item csas-ist-item--width2 csas-ist-item--height2"></div>
  <div class="csas-ist-item csas-ist-item--width2"></div>
  <div class="csas-ist-item csas-ist-item--width2"></div>
  <div class="csas-ist-item csas-ist-item--height2"></div>
  <div class="csas-ist-item"></div>
  <div class="csas-ist-item csas-ist-item--width2"></div>
  <div class="csas-ist-item csas-ist-item--height2"></div>
  <div class="csas-ist-item"></div>
  <div class="csas-ist-item"></div>
  ';

  $dat_opt = array(
    'itemSelector' => '.csas-ist-item',
    'layoutMode' => 'packery',
  );

  $dat_opt = (object)$dat_opt;

  $build['wr']['packery'] = array(
    '#prefix' => '<h2>Isotope - packery layout mode</h2>',
    '#type' => 'container',

    '#attached' => array(
      'library' => array(
        array('csas_ist', 'csas_ist'),
        array('csas_ist', 'csas_ist_packery_mode'),
      )
    ),
    '#attributes' => array(
      'class' => array(
        'csas-ist-grid',
        'csas-ist-demo',
        'csas-ist-demo-pac'
      ),
      'data-options' => drupal_json_encode($dat_opt)
    ),
    'content' => array('#markup' => $content),
  );


  return $build;
}